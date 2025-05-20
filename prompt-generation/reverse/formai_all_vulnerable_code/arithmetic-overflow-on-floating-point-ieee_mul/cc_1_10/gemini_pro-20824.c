//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of a triangle given its base and height
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the volume of a cylinder given its radius and height
double cylinder_volume(double radius, double height) {
    return M_PI * radius * radius * height;
}

// Function to calculate the surface area of a sphere given its radius
double sphere_surface_area(double radius) {
    return 4 * M_PI * radius * radius;
}

int main() {
    // Get the base and height of the triangle from the user
    double base, height;
    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &base, &height);

    // Calculate the area of the triangle
    double triangle_area_result = triangle_area(base, height);

    // Get the radius and height of the cylinder from the user
    double radius, cyl_height;
    printf("Enter the radius and height of the cylinder: ");
    scanf("%lf %lf", &radius, &cyl_height);

    // Calculate the volume of the cylinder
    double cylinder_volume_result = cylinder_volume(radius, cyl_height);

    // Get the radius of the sphere from the user
    double sphere_radius;
    printf("Enter the radius of the sphere: ");
    scanf("%lf", &sphere_radius);

    // Calculate the surface area of the sphere
    double sphere_surface_area_result = sphere_surface_area(sphere_radius);

    // Print the results to the user
    printf("The area of the triangle is: %.2lf\n", triangle_area_result);
    printf("The volume of the cylinder is: %.2lf\n", cylinder_volume_result);
    printf("The surface area of the sphere is: %.2lf\n", sphere_surface_area_result);

    return 0;
}