//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <math.h>

// This program finds the intersection of two circles.
// What is the intersection of two circles?
// It is the set of all points that are inside both circles.
// We can find the intersection of two circles by finding
// all the points that are inside both circles.
// We can do this by drawing a line connecting the centers
// of the two circles.
// The intersection of the two circles will be the intersection
// of the line and the two circles.

// The following function computes the intersection of
// two circles.

void findIntersection() {
  // The program reads two circles from the user,
  // and then it computes their intersection.
  // The user enters the center of the first circle,
  // the radius of the first circle,
  // the center of the second circle,
  // and the radius of the second circle.
  // The program then prints the intersection of
  // the two circles.

  // Define the variables.
  double x1, y1, r1, x2, y2, r2, dx, dy, d, x, y;

  // Read the input.
  printf("Enter the center of the first circle: ");
  scanf("%lf %lf", &x1, &y1);
  printf("Enter the radius of the first circle: ");
  scanf("%lf", &r1);
  printf("Enter the center of the second circle: ");
  scanf("%lf %lf", &x2, &y2);
  printf("Enter the radius of the second circle: ");
  scanf("%lf", &r2);

  // Compute the distance between the centers of the two circles.
  dx = x2 - x1;
  dy = y2 - y1;
  d = sqrt(dx * dx + dy * dy);

  // Check if the two circles intersect.
  if (d > r1 + r2) {
    printf("The two circles do not intersect.\n");
    return;
  }

  // Compute the intersection point.
  x = (x1 * r2 + x2 * r1) / (r1 + r2);
  y = (y1 * r2 + y2 * r1) / (r1 + r2);

  // Print the intersection point.
  printf("The intersection point is: (%lf, %lf)\n", x, y);
}

int main() {
  findIntersection();
  return 0;
}