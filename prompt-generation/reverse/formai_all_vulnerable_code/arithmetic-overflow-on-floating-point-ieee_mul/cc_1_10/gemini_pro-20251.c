//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Define some constants
  const double PI = 3.14159265358979323846;
  const double E = 2.71828182845904523536;

  // Get some input from the user
  printf("Enter a number: ");
  double x;
  scanf("%lf", &x);

  // Perform some mathematical operations on the input
  double y = sin(x);
  double z = cos(x);
  double w = tan(x);
  double v = log(x);
  double u = exp(x);

  // Print the results
  printf("sin(%lf) = %lf\n", x, y);
  printf("cos(%lf) = %lf\n", x, z);
  printf("tan(%lf) = %lf\n", x, w);
  printf("log(%lf) = %lf\n", x, v);
  printf("exp(%lf) = %lf\n", x, u);

  // Compute the area of a circle with radius r
  printf("Enter the radius of a circle: ");
  double r;
  scanf("%lf", &r);
  double area = PI * r * r;
  printf("The area of the circle is %lf\n", area);

  // Compute the volume of a sphere with radius r
  printf("Enter the radius of a sphere: ");
  scanf("%lf", &r);
  double volume = (4 / 3) * PI * r * r * r;
  printf("The volume of the sphere is %lf\n", volume);

  // Compute the distance between two points (x1, y1) and (x2, y2)
  printf("Enter the coordinates of the first point: ");
  double x1, y1;
  scanf("%lf %lf", &x1, &y1);
  printf("Enter the coordinates of the second point: ");
  double x2, y2;
  scanf("%lf %lf", &x2, &y2);
  double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  printf("The distance between the two points is %lf\n", distance);

  // Compute the roots of a quadratic equation ax^2 + bx + c = 0
  printf("Enter the coefficients of the quadratic equation: ");
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  double discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    printf("The equation has no real roots\n");
  } else {
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("The roots of the equation are %lf and %lf\n", root1, root2);
  }

  // Compute the nth Fibonacci number
  printf("Enter the index of the Fibonacci number: ");
  int n;
  scanf("%d", &n);
  int fib1 = 0;
  int fib2 = 1;
  int fibn;
  for (int i = 2; i <= n; i++) {
    fibn = fib1 + fib2;
    fib1 = fib2;
    fib2 = fibn;
  }
  printf("The %dth Fibonacci number is %d\n", n, fibn);

  return 0;
}