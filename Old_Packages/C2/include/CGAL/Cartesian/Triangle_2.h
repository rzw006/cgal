// revision      : $Revision$
// revision_date : $Date$
// author(s)     : Andreas Fabri, Herve Bronnimann

#ifndef CGAL_CARTESIAN_TRIANGLE_2_H
#define CGAL_CARTESIAN_TRIANGLE_2_H

#include <CGAL/Cartesian/redefine_names_2.h>
#include <CGAL/Threetuple.h>

CGAL_BEGIN_NAMESPACE

template <class _R>
class TriangleC2
#ifndef CGAL_CFG_NO_ADVANCED_KERNEL
// This is a partial specialization
<_R,Cartesian_tag>
#endif
  : public Handle
{
public:
  typedef _R                                    R;
  typedef typename R::FT                        FT;
  typedef typename R::RT                        RT;
#ifndef CGAL_CFG_NO_ADVANCED_KERNEL
  typedef TriangleC2<R,Cartesian_tag>           Self;
  typedef typename R::Point_2                   Point_2;
  typedef typename R::Vector_2                  Vector_2;
  typedef typename R::Direction_2               Direction_2;
  typedef typename R::Line_2                    Line_2;
  typedef typename R::Ray_2                     Ray_2;
  typedef typename R::Segment_2                 Segment_2;
  typedef typename R::Iso_rectangle_2           Iso_rectangle_2;
  typedef typename R::Aff_transformation_2      Aff_transformation_2;
  typedef typename R::Circle_2                  Circle_2;
#else
  typedef TriangleC2<R>                         Self;
  typedef typename R::Point_2_base              Point_2;
  typedef typename R::Vector_2_base             Vector_2;
  typedef typename R::Direction_2_base          Direction_2;
  typedef typename R::Line_2_base               Line_2;
  typedef typename R::Ray_2_base                Ray_2;
  typedef typename R::Segment_2_base            Segment_2;
  typedef typename R::Iso_rectangle_2_base      Iso_rectangle_2;
  typedef typename R::Aff_transformation_2_base Aff_transformation_2;
  typedef typename R::Circle_2_base             Circle_2;
#endif

  TriangleC2();
  TriangleC2(const Self &);
  TriangleC2(const Point_2 &p, const Point_2 &q, const Point_2 &r);
  ~TriangleC2();

  Self           &operator=(const Self &t);

  bool           operator==(const Self &s) const;
  bool           operator!=(const Self &s) const;
  int            id() const;

  Point_2        vertex(int i) const;
  Point_2        operator[](int i) const;

  Self           transform(const Aff_transformation_2 &t) const;
  Self           opposite() const;

  Orientation    orientation() const;
  Oriented_side  oriented_side(const Point_2 &p) const;
  Bounded_side   bounded_side(const Point_2 &p) const;

  bool           has_on_boundary(const Point_2 &p) const;

  bool           has_on_bounded_side(const Point_2 &p) const;
  bool           has_on_unbounded_side(const Point_2 &p) const;

  bool           has_on_positive_side(const Point_2 &p) const;
  bool           has_on_negative_side(const Point_2 &p) const;

  bool           is_degenerate() const;

  Bbox_2         bbox() const;

private:
  _Threetuple< Point_2 >*   ptr() const;
};

CGAL_END_NAMESPACE

#ifndef CGAL_CARTESIAN_CLASS_DEFINED
#include <CGAL/Cartesian/Triangle_2.C>
#endif 

#endif // CGAL_CARTESIAN_TRIANGLE_2_H
