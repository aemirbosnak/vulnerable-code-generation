//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point struct
typedef struct Point {
  double x;
  double y;
} Point;

// Define a line struct
typedef struct Line {
  Point p1;
  Point p2;
} Line;

// Define function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Define function to calculate the slope of a line
double slope(Line line) {
  return (line.p2.y - line.p1.y) / (line.p2.x - line.p1.x);
}

// Define function to calculate the y-intercept of a line
double yIntercept(Line line) {
  return line.p1.y - slope(line) * line.p1.x;
}

// Define function to calculate the intersection point of two lines
Point intersection(Line line1, Line line2) {
  double x = (yIntercept(line2) - yIntercept(line1)) / (slope(line1) - slope(line2));
  double y = slope(line1) * x + yIntercept(line1);
  Point intersectionPoint = {x, y};
  return intersectionPoint;
}

// Define function to calculate the distance between a point and a line
double pointToLineDistance(Point point, Line line) {
  double numerator = fabs((line.p2.y - line.p1.y) * point.x - (line.p2.x - line.p1.x) * point.y + line.p2.x * line.p1.y - line.p2.y * line.p1.x);
  double denominator = sqrt(pow(line.p2.y - line.p1.y, 2) + pow(line.p2.x - line.p1.x, 2));
  return numerator / denominator;
}

int main() {
  Point p1 = {0, 0};
  Point p2 = {3, 0};
  Point p3 = {3, 3};
  Line line1 = {p1, p2};
  Line line2 = {p2, p3};
  Point intersectionPoint = intersection(line1, line2);
  double distanceToPoint = pointToLineDistance(p3, line1);
  printf("Intersection Point: (%lf, %lf)\n", intersectionPoint.x, intersectionPoint.y);
  printf("Point to Line Distance: %lf\n", distanceToPoint);
  return 0;
}