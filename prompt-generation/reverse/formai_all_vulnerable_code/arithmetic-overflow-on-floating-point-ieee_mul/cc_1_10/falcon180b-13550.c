//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the perimeter of a rectangle
double rectangle_perimeter(double width, double height) {
    return 2 * (width + height);
}

// Function to calculate the area of a rectangle
double rectangle_area(double width, double height) {
    return width * height;
}

// Function to calculate the area of a circle
double circle_area(double radius) {
    return M_PI * pow(radius, 2);
}

// Function to calculate the circumference of a circle
double circle_circumference(double radius) {
    return 2 * M_PI * radius;
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4.0/3.0) * M_PI * pow(radius, 3);
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
    return 4 * M_PI * pow(radius, 2);
}

int main() {
    // Example usage
    double triangle_base = 10.0;
    double triangle_height = 5.0;
    double rectangle_width = 15.0;
    double rectangle_height = 8.0;
    double circle_radius = 7.0;
    double sphere_radius = 6.0;

    printf("Triangle Area: %.2lf\n", triangle_area(triangle_base, triangle_height));
    printf("Rectangle Perimeter: %.2lf\n", rectangle_perimeter(rectangle_width, rectangle_height));
    printf("Rectangle Area: %.2lf\n", rectangle_area(rectangle_width, rectangle_height));
    printf("Circle Area: %.2lf\n", circle_area(circle_radius));
    printf("Circle Circumference: %.2lf\n", circle_circumference(circle_radius));
    printf("Sphere Volume: %.2lf\n", sphere_volume(sphere_radius));
    printf("Sphere Surface Area: %.2lf\n", sphere_surface_area(sphere_radius));

    return 0;
}