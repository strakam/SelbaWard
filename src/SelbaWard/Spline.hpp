//////////////////////////////////////////////////////////////////////////////
//
// Selba Ward (https://github.com/Hapaxia/SelbaWard)
// --
//
// Spline
//
// Copyright(c) 2014-2015 M.J.Silk
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions :
//
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software.If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
// M.J.Silk
// MJSilk2@gmail.com
//
//////////////////////////////////////////////////////////////////////////////

#ifndef SELBAWARD_SPLINE_HPP
#define SELBAWARD_SPLINE_HPP

#include "Common.hpp"

namespace selbaward
{

class Spline : public sf::Drawable
{
public:
	struct Vertex
	{
		sf::Vector2f position;
		Vertex() {}
		Vertex(sf::Vector2f newPosition) : position(newPosition) {}
	};

	Spline();
	void update();

	const unsigned int getVertexCount() const;
	const unsigned int getLastVertexIndex() const;

	void reserveVertices(unsigned int numberOfVertices);

	void addVertices(const std::vector<sf::Vector2f>& positions);
	void addVertices(unsigned int index, const std::vector<sf::Vector2f>& positions); // inserts the new vertices before the vertex at the specified index
	void addVertices(unsigned int numberOfVertices, sf::Vector2f position = { 0.f, 0.f });
	void addVertices(unsigned int numberOfVertices, unsigned int index, sf::Vector2f position = { 0.f, 0.f }); // inserts the new vertices before the vertex at the specified index
	void addVertex(sf::Vector2f position = { 0.f, 0.f });
	void addVertex(unsigned int index, sf::Vector2f position = { 0.f, 0.f }); // inserts the new vertex before the vertex at the specified index
	void removeVertex(unsigned int index);
	void removeVertices(unsigned int index, unsigned int numberOfVertices = 0u); // if numberOfvertices is zero (the default), removes all vertices from specified index until the end
	void reverseVertices();
	
	void setPosition(unsigned int index, sf::Vector2f position = { 0.f, 0.f });
	void setPositions(unsigned int index, unsigned int numberOfVertices = 0u, sf::Vector2f position = { 0.f, 0.f }); // if numberOfvertices is zero (the default), sets positions of all vertices from specified index until the end
	void setPositions(const std::vector<sf::Vector2f>& vertices, unsigned int index = 0u);
	const sf::Vector2f getPosition(unsigned int index) const;

	void setColor(sf::Color color);
	const sf::Color getColor() const;

	void setInterpolationSteps(unsigned int interpolationSteps);
	const unsigned int getInterpolationSteps() const;

	void dev_flipPrimitiveType(); // temporary (for development) method that alternates primitive types: lines strip and points

private:
	const std::string m_exceptionPrefix;

	bool m_throwExceptions;

	std::vector<Vertex> m_vertices;
	sf::Color m_color;

	std::vector<sf::Vertex> m_sfmlVertices;
	sf::PrimitiveType m_primitiveType;
	unsigned int m_interpolationSteps;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	const bool priv_isValidVertexIndex(unsigned int vertexIndex) const;
	const bool priv_testVertexIndex(unsigned int vertexIndex, const std::string& exceptionMessage) const;
};

inline const unsigned int Spline::getVertexCount() const
{
	return m_vertices.size();
}

inline const unsigned int Spline::getLastVertexIndex() const
{
	return m_vertices.size() - 1u;
}

inline const sf::Color Spline::getColor() const
{
	return m_color;
}

inline const unsigned int Spline::getInterpolationSteps() const
{
	return m_interpolationSteps;
}

} // namespace selbaward
#endif // SELBAWARD_SPLINE_HPP
