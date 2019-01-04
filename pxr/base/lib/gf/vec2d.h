//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////
// This file is generated by a script.  Do not edit directly.  Edit the
// vec.template.h file to make changes.

#ifndef GF_VEC2D_H
#define GF_VEC2D_H

/// \file gf/vec2d.h
/// \ingroup group_gf_LinearAlgebra

#include "pxr/pxr.h"
#include "pxr/base/tf/diagnostic.h"
#include "pxr/base/gf/api.h"
#include "pxr/base/gf/limits.h"
#include "pxr/base/gf/traits.h"
#include "pxr/base/gf/math.h"

#include <boost/functional/hash.hpp>

#include <cstddef>
#include <cmath>

#include <iosfwd>

PXR_NAMESPACE_OPEN_SCOPE

class GfVec2d;

template <>
struct GfIsGfVec<class GfVec2d> { static const bool value = true; };

/// \class GfVec2d
/// \ingroup group_gf_LinearAlgebra
///
/// Basic type for a vector of 2 double components.
///
/// Represents a vector of 2 components of type \c double.
/// It is intended to be fast and simple.
///
class GfVec2d
{
public:
    /// Scalar element type and dimension.
    typedef double ScalarType;
    static const size_t dimension = 2;

    /// Default constructor does no initialization.
    GfVec2d() {}

    // Copy constructor.
    // TODO Remove this, use compiler-generated.
    GfVec2d(const GfVec2d &other) {
        *this = other;
    }

    /// Initialize all elements to a single value.
    explicit GfVec2d(double value) {
        _data[0] = value;
        _data[1] = value;
    }

    /// Initialize all elements with explicit arguments.
    GfVec2d(double s0, double s1) {
        Set(s0, s1);
    }

    /// Construct with pointer to values.
    template <class Scl>
    explicit GfVec2d(Scl const *p) { Set(p); }

    /// Implicitly convert from GfVec2f.
    GfVec2d(class GfVec2f const &other);

    /// Implicitly convert from GfVec2h.
    GfVec2d(class GfVec2h const &other);

    /// Implicitly convert from GfVec2i.
    GfVec2d(class GfVec2i const &other);
 
    /// Create a unit vector along the X-axis.
    static GfVec2d XAxis() {
        GfVec2d result(0);
        result[0] = 1;
        return result;
    }
    /// Create a unit vector along the Y-axis.
    static GfVec2d YAxis() {
        GfVec2d result(0);
        result[1] = 1;
        return result;
    }

    /// Create a unit vector along the i-th axis, zero-based.  Return the zero
    /// vector if \p i is greater than or equal to 2.
    static GfVec2d Axis(size_t i) {
        GfVec2d result(0);
        if (i < 2)
            result[i] = 1;
        return result;
    }

    /// Set all elements with passed arguments.
    GfVec2d &Set(double s0, double s1) {
        _data[0] = s0;
        _data[1] = s1;
        return *this;
    }

    /// Set all elements with a pointer to data.
    GfVec2d &Set(double const *a) {
        return Set(a[0], a[1]);
    }

    /// Direct data access.
    double const *data() const { return _data; }
    double *data() { return _data; }
    double const *GetArray() const { return data(); }

    /// Indexing.
    double const &operator[](size_t i) const { return _data[i]; }
    double &operator[](size_t i) { return _data[i]; }

    /// Hash.
    friend inline size_t hash_value(GfVec2d const &vec) {
        size_t h = 0;
        boost::hash_combine(h, vec[0]);
        boost::hash_combine(h, vec[1]);
        return h;
    }

    /// Equality comparison.
    bool operator==(GfVec2d const &other) const {
        return _data[0] == other[0] &&
               _data[1] == other[1];
    }
    bool operator!=(GfVec2d const &other) const {
        return !(*this == other);
    }

    // TODO Add inequality for other vec types...
    /// Equality comparison.
    GF_API
    bool operator==(class GfVec2f const &other) const;
    /// Equality comparison.
    GF_API
    bool operator==(class GfVec2h const &other) const;
    /// Equality comparison.
    GF_API
    bool operator==(class GfVec2i const &other) const;
    
    /// Create a vec with negated elements.
    GfVec2d operator-() const {
        return GfVec2d(-_data[0], -_data[1]);
    }

    /// Addition.
    GfVec2d &operator+=(GfVec2d const &other) {
        _data[0] += other[0];
        _data[1] += other[1];
        return *this;
    }
    friend GfVec2d operator+(GfVec2d const &l, GfVec2d const &r) {
        return GfVec2d(l) += r;
    }

    /// Subtraction.
    GfVec2d &operator-=(GfVec2d const &other) {
        _data[0] -= other[0];
        _data[1] -= other[1];
        return *this;
    }
    friend GfVec2d operator-(GfVec2d const &l, GfVec2d const &r) {
        return GfVec2d(l) -= r;
    }

    /// Multiplication by scalar.
    GfVec2d &operator*=(double s) {
        _data[0] *= s;
        _data[1] *= s;
        return *this;
    }
    GfVec2d operator*(double s) const {
        return GfVec2d(*this) *= s;
    }
    friend GfVec2d operator*(double s, GfVec2d const &v) {
        return v * s;
    }

        /// Division by scalar.
    // TODO should divide by the scalar type.
    GfVec2d &operator/=(double s) {
        // TODO This should not multiply by 1/s, it should do the division.
        // Doing the division is more numerically stable when s is close to
        // zero.
        return *this *= (1.0 / s);
    }
    GfVec2d operator/(double s) const {
        return *this * (1.0 / s);
    }
    
    /// See GfDot().
    double operator*(GfVec2d const &v) const {
        return _data[0] * v[0] + _data[1] * v[1];
    }

    /// Returns the projection of \p this onto \p v. That is:
    /// \code
    /// v * (*this * v)
    /// \endcode
    GfVec2d GetProjection(GfVec2d const &v) const {
        return v * (*this * v);
    }

    /// Returns the orthogonal complement of \p this->GetProjection(b).
    /// That is:
    /// \code
    ///  *this - this->GetProjection(b)
    /// \endcode
    GfVec2d GetComplement(GfVec2d const &b) const {
        return *this - this->GetProjection(b);
    }

    /// Squared length.
    double GetLengthSq() const {
        return *this * *this;
    }

    /// Length
    double GetLength() const {
        // TODO should use GfSqrt.
        return sqrt(GetLengthSq());
    }

    /// Normalizes the vector in place to unit length, returning the
    /// length before normalization. If the length of the vector is
    /// smaller than \p eps, then the vector is set to vector/\c eps.
    /// The original length of the vector is returned. See also GfNormalize().
    ///
    /// \todo This was fixed for bug 67777. This is a gcc64 optimizer bug.
    /// By tickling the code, it no longer tries to write into
    /// an illegal memory address (in the code section of memory).
    double Normalize(double eps = GF_MIN_VECTOR_LENGTH) {
        // TODO this seems suspect...  suggest dividing by length so long as
        // length is not zero.
        double length = GetLength();
        *this /= (length > eps) ? length : eps;
        return length;
    }

    GfVec2d GetNormalized(double eps = GF_MIN_VECTOR_LENGTH) const {
        GfVec2d normalized(*this);
        normalized.Normalize(eps);
        return normalized;
    }

  
private:
    double _data[2];
};

/// Output a GfVec2d.
/// \ingroup group_gf_DebuggingOutput
GF_API std::ostream& operator<<(std::ostream &, GfVec2d const &);


PXR_NAMESPACE_CLOSE_SCOPE

#include "pxr/base/gf/vec2f.h"
#include "pxr/base/gf/vec2h.h"
#include "pxr/base/gf/vec2i.h"

PXR_NAMESPACE_OPEN_SCOPE

inline
GfVec2d::GfVec2d(class GfVec2f const &other)
{
    _data[0] = other[0];
    _data[1] = other[1];
}
inline
GfVec2d::GfVec2d(class GfVec2h const &other)
{
    _data[0] = other[0];
    _data[1] = other[1];
}
inline
GfVec2d::GfVec2d(class GfVec2i const &other)
{
    _data[0] = other[0];
    _data[1] = other[1];
}

/// Returns component-wise multiplication of vectors \p v1 and \p v2.
inline GfVec2d
GfCompMult(GfVec2d const &v1, GfVec2d const &v2) {
    return GfVec2d(
        v1[0] * v2[0],
        v1[1] * v2[1]
        );
}

/// Returns component-wise quotient of vectors \p v1 and \p v2.
inline GfVec2d
GfCompDiv(GfVec2d const &v1, GfVec2d const &v2) {
    return GfVec2d(
        v1[0] / v2[0],
        v1[1] / v2[1]
        );
}

/// Returns the dot (inner) product of two vectors.
inline double
GfDot(GfVec2d const &v1, GfVec2d const &v2) {
    return v1 * v2;
}


/// Returns the geometric length of \c v.
inline double
GfGetLength(GfVec2d const &v)
{
    return v.GetLength();
}

/// Normalizes \c *v in place to unit length, returning the length before
/// normalization. If the length of \c *v is smaller than \p eps then \c *v is
/// set to \c *v/eps.  The original length of \c *v is returned.
inline double
GfNormalize(GfVec2d *v, double eps = GF_MIN_VECTOR_LENGTH)
{
    return v->Normalize(eps);
}

/// Returns a normalized (unit-length) vector with the same direction as \p v.
/// If the length of this vector is smaller than \p eps, the vector divided by
/// \p eps is returned.
inline GfVec2d
GfGetNormalized(GfVec2d const &v, double eps = GF_MIN_VECTOR_LENGTH)
{
    return v.GetNormalized(eps);
}

/// Returns the projection of \p a onto \p b. That is:
/// \code
/// b * (a * b)
/// \endcode
inline GfVec2d
GfGetProjection(GfVec2d const &a, GfVec2d const &b)
{
    return a.GetProjection(b);
}

/// Returns the orthogonal complement of \p a.GetProjection(b). That is:
/// \code
///  a - a.GetProjection(b)
/// \endcode
inline GfVec2d
GfGetComplement(GfVec2d const &a, GfVec2d const &b)
{
    return a.GetComplement(b);
}

/// Tests for equality within a given tolerance, returning \c true if the
/// length of the difference vector is less than or equal to \p tolerance.
inline bool
GfIsClose(GfVec2d const &v1, GfVec2d const &v2, double tolerance)
{
    GfVec2d delta = v1 - v2;
    return delta.GetLengthSq() <= tolerance * tolerance;
}

 
 
PXR_NAMESPACE_CLOSE_SCOPE

#endif // GF_VEC2D_H
