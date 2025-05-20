//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
    return (base * height) / 2;
}

// Function to calculate the perimeter of a triangle
double triangle_perimeter(double side1, double side2, double side3) {
    double perimeter = 0;
    perimeter += side1;
    perimeter += side2;
    perimeter += side3;
    return perimeter;
}

// Function to calculate the area of a rectangle
double rectangle_area(double width, double height) {
    return width * height;
}

// Function to calculate the perimeter of a rectangle
double rectangle_perimeter(double width, double height) {
    double perimeter = 0;
    perimeter += 2 * width;
    perimeter += 2 * height;
    return perimeter;
}

// Function to calculate the area of a circle
double circle_area(double radius) {
    return PI * radius * radius;
}

// Function to calculate the circumference of a circle
double circle_circumference(double radius) {
    return 2 * PI * radius;
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
    return 4 * PI * radius * radius;
}

int main() {
    double base, height, side1, side2, side3, width, height_rect, radius, volume, surface_area;
    printf("Enter the base and height of a triangle: ");
    scanf("%lf %lf", &base, &height);
    printf("The area of a triangle with base %.2lf and height %.2lf is %.2lf\n", base, height, triangle_area(base, height));
    printf("The perimeter of a triangle with base %.2lf and height %.2lf is %.2lf\n", base, height, triangle_perimeter(base, height, 0));

    printf("Enter the dimensions of a rectangle: ");
    scanf("%lf %lf", &width, &height);
    printf("The area of a rectangle with width %.2lf and height %.2lf is %.2lf\n", width, height, rectangle_area(width, height));
    printf("The perimeter of a rectangle with width %.2lf and height %.2lf is %.2lf\n", width, height, rectangle_perimeter(width, height));

    printf("Enter the radius of a circle: ");
    scanf("%lf", &radius);
    printf("The area of a circle with radius %.2lf is %.2lf\n", radius, circle_area(radius));
    printf("The circumference of a circle with radius %.2lf is %.2lf\n", radius, circle_circumference(radius));

    printf("Enter the radius of a sphere: ");
    scanf("%lf", &radius);
    printf("The volume of a sphere with radius %.2lf is %.2lf\n", radius, sphere_volume(radius));
    printf("The surface area of a sphere with radius %.2lf is %.2lf\n", radius, sphere_surface_area(radius));

    return 0;
}