//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

double find_distance(double x1, double y1, double x2, double y2);
double find_slope(double x1, double y1, double x2, double y2);
double find_area_of_triangle(double base, double height);
double find_circumference_of_circle(double radius);

int main(void) {
    // Initializing the variables
    double x1, y1, x2, y2, radius, base, height;

    // Getting the user input
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);

    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);

    // Calculating the distance between the two points
    double distance = find_distance(x1, y1, x2, y2);
    printf("The distance between the two points is: %.2lf\n", distance);

    // Calculating the slope of the line connecting the two points
    double slope = find_slope(x1, y1, x2, y2);
    printf("The slope of the line connecting the two points is: %.2lf\n", slope);

    // Calculating the area of the triangle
    double area_of_triangle = find_area_of_triangle(base, height);
    printf("The area of the triangle is: %.2lf\n", area_of_triangle);

    // Calculating the circumference of the circle
    double circumference_of_circle = find_circumference_of_circle(radius);
    printf("The circumference of the circle is: %.2lf\n", circumference_of_circle);

    return 0;
}

double find_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double find_slope(double x1, double y1, double x2, double y2) {
    return (y2 - y1) / (x2 - x1);
}

double find_area_of_triangle(double base, double height) {
    return 0.5 * base * height;
}

double find_circumference_of_circle(double radius) {
    return 2 * 3.14159 * radius;
}