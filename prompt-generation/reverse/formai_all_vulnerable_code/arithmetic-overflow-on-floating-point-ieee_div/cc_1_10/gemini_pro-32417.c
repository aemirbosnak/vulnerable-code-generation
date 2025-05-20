//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a point
typedef struct point {
  double x;
  double y;
} point;

// Define the data structure for a line segment
typedef struct line_segment {
  point p1;
  point p2;
} line_segment;

// Define the function to calculate the distance between two points
double distance(point p1, point p2) {
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Define the function to calculate the intersection point of two line segments
point intersection_point(line_segment l1, line_segment l2) {
  // Calculate the slope and y-intercept of the first line segment
  double m1 = (l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
  double b1 = l1.p1.y - m1 * l1.p1.x;

  // Calculate the slope and y-intercept of the second line segment
  double m2 = (l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);
  double b2 = l2.p1.y - m2 * l2.p1.x;

  // If the two lines are parallel, there is no intersection point
  if (m1 == m2) {
    return (point) {-1, -1};
  }

  // Calculate the intersection point
  double x = (b2 - b1) / (m1 - m2);
  double y = m1 * x + b1;

  return (point) {x, y};
}

int main() {
  // Define two line segments
  line_segment l1 = {{0, 0}, {10, 10}};
  line_segment l2 = {{5, 0}, {5, 10}};

  // Calculate the intersection point of the two line segments
  point intersection = intersection_point(l1, l2);

  // Print the intersection point
  printf("The intersection point is (%f, %f)\n", intersection.x, intersection.y);

  return 0;
}