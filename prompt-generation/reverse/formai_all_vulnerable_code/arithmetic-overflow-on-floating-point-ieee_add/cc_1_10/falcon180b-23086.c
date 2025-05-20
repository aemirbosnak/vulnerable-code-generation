//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the perimeter of a rectangle
double rectangle_perimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4.0 / 3.0) * M_PI * radius * radius * radius;
}

// Function to calculate the surface area of a cylinder
double cylinder_surface_area(double radius, double height) {
    double base_area = M_PI * radius * radius;
    double side_area = 2 * M_PI * radius * height;
    return base_area + side_area;
}

// Function to calculate the volume of a cone
double cone_volume(double radius, double height) {
    return (1.0 / 3.0) * M_PI * radius * radius * height;
}

int main() {
    double base, height, length, width, radius, height2, volume, area, perimeter, surface_area;

    // Get user input for triangle
    printf("Enter the base and height of a triangle: ");
    scanf("%lf %lf", &base, &height);
    printf("The area of the triangle is %lf\n", triangle_area(base, height));

    // Get user input for rectangle
    printf("Enter the length and width of a rectangle: ");
    scanf("%lf %lf", &length, &width);
    printf("The perimeter of the rectangle is %lf\n", rectangle_perimeter(length, width));

    // Get user input for sphere
    printf("Enter the radius of a sphere: ");
    scanf("%lf", &radius);
    printf("The volume of the sphere is %lf\n", sphere_volume(radius));

    // Get user input for cylinder
    printf("Enter the radius and height of a cylinder: ");
    scanf("%lf %lf", &radius, &height);
    printf("The surface area of the cylinder is %lf\n", cylinder_surface_area(radius, height));

    // Get user input for cone
    printf("Enter the radius and height of a cone: ");
    scanf("%lf %lf", &radius, &height);
    printf("The volume of the cone is %lf\n", cone_volume(radius, height));

    return 0;
}