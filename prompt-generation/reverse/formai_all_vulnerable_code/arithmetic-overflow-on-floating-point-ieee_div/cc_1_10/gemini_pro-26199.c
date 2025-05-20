//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point in 2D space
typedef struct {
  double x;
  double y;
} Point;

// Define a line segment
typedef struct {
  Point p1;
  Point p2;
} LineSegment;

// Define a circle
typedef struct {
  Point center;
  double radius;
} Circle;

// Function to check if a point is inside a circle
int is_point_in_circle(Point point, Circle circle) {
  double dx = point.x - circle.center.x;
  double dy = point.y - circle.center.y;
  return dx * dx + dy * dy <= circle.radius * circle.radius;
}

// Function to check if two line segments intersect
int do_line_segments_intersect(LineSegment ls1, LineSegment ls2) {
  // Get the slopes of the two lines
  double m1 = (ls1.p2.y - ls1.p1.y) / (ls1.p2.x - ls1.p1.x);
  double m2 = (ls2.p2.y - ls2.p1.y) / (ls2.p2.x - ls2.p1.x);

  // If the slopes are equal, the lines are parallel and cannot intersect
  if (m1 == m2) {
    return 0;
  }

  // Get the y-intercepts of the two lines
  double b1 = ls1.p1.y - m1 * ls1.p1.x;
  double b2 = ls2.p1.y - m2 * ls2.p1.x;

  // Get the x-coordinate where the lines intersect
  double x = (b2 - b1) / (m1 - m2);

  // Check if the x-coordinate is within the bounds of both line segments
  return x >= ls1.p1.x && x <= ls1.p2.x && x >= ls2.p1.x && x <= ls2.p2.x;
}

// Main function
int main() {
  // Create a point
  Point point = {1.0, 2.0};

  // Create a circle
  Circle circle = {{3.0, 4.0}, 5.0};

  // Check if the point is inside the circle
  int is_inside = is_point_in_circle(point, circle);
  printf("Is the point inside the circle? %s\n", is_inside ? "Yes" : "No");

  // Create two line segments
  LineSegment ls1 = {{0.0, 0.0}, {10.0, 10.0}};
  LineSegment ls2 = {{5.0, 0.0}, {5.0, 10.0}};

  // Check if the two line segments intersect
  int do_intersect = do_line_segments_intersect(ls1, ls2);
  printf("Do the two line segments intersect? %s\n", do_intersect ? "Yes" : "No");

  return 0;
}