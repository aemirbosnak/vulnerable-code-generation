//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate the area of a circle
double circle_area(double radius) {
    return 3.14159265358979323846 * radius * radius;
}

// Function to calculate the circumference of a circle
double circle_circumference(double radius) {
    return 2 * 3.14159265358979323846 * radius;
}

// Function to calculate the surface area of a sphere
double sphere_surface_area(double radius) {
    return 4 * PI * radius * radius;
}

// Function to calculate the volume of a sphere
double sphere_volume(double radius) {
    return (4/3) * PI * radius * radius * radius;
}

int main() {
    double radius, area, circumference, surface_area, volume;

    // Input radius for circle calculations
    printf("Enter radius: ");
    scanf("%lf", &radius);

    // Calculate area, circumference, and surface area of circle
    area = circle_area(radius);
    circumference = circle_circumference(radius);
    surface_area = sphere_surface_area(radius);

    // Print results
    printf("Circle area: %lf\n", area);
    printf("Circle circumference: %lf\n", circumference);
    printf("Sphere surface area: %lf\n", surface_area);

    // Input radius for sphere calculations
    printf("Enter radius: ");
    scanf("%lf", &radius);

    // Calculate volume of sphere
    volume = sphere_volume(radius);

    // Print result
    printf("Sphere volume: %lf\n", volume);

    return 0;
}