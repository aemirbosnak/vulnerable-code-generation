//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the area of a triangle
double triangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a circle
double circleArea(double radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the area of a sphere
double sphereArea(double radius) {
    return 4 * 3.14159 * radius * radius;
}

// Function to calculate the volume of a sphere
double sphereVolume(double radius) {
    return (4 / 3) * 3.14159 * radius * radius * radius;
}

// Function to calculate the volume of a cone
double coneVolume(double radius, double height) {
    return (1 / 3) * 3.14159 * radius * radius * height;
}

// Function to calculate the volume of a cylinder
double cylinderVolume(double radius, double height) {
    return 3.14159 * radius * radius * height;
}

// Function to calculate the surface area of a cylinder
double cylinderSurfaceArea(double radius, double height) {
    return 2 * 3.14159 * radius * (radius + height);
}

// Function to calculate the surface area of a sphere
double sphereSurfaceArea(double radius) {
    return 4 * 3.14159 * radius * radius;
}

// Function to calculate the surface area of a cone
double coneSurfaceArea(double radius, double height) {
    return 3.14159 * radius * (radius + sqrt(height * height + radius * radius));
}

int main() {
    // Define the variables
    double base, height, radius;

    // Get the input from the user
    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate the area of the triangle
    double triangleAreaValue = triangleArea(base, height);

    // Calculate the area of the circle
    double circleAreaValue = circleArea(radius);

    // Calculate the area of the sphere
    double sphereAreaValue = sphereArea(radius);

    // Calculate the volume of the sphere
    double sphereVolumeValue = sphereVolume(radius);

    // Calculate the volume of the cone
    double coneVolumeValue = coneVolume(radius, height);

    // Calculate the volume of the cylinder
    double cylinderVolumeValue = cylinderVolume(radius, height);

    // Calculate the surface area of the cylinder
    double cylinderSurfaceAreaValue = cylinderSurfaceArea(radius, height);

    // Calculate the surface area of the sphere
    double sphereSurfaceAreaValue = sphereSurfaceArea(radius);

    // Calculate the surface area of the cone
    double coneSurfaceAreaValue = coneSurfaceArea(radius, height);

    // Print the results
    printf("The area of the triangle is: %lf\n", triangleAreaValue);
    printf("The area of the circle is: %lf\n", circleAreaValue);
    printf("The area of the sphere is: %lf\n", sphereAreaValue);
    printf("The volume of the sphere is: %lf\n", sphereVolumeValue);
    printf("The volume of the cone is: %lf\n", coneVolumeValue);
    printf("The volume of the cylinder is: %lf\n", cylinderVolumeValue);
    printf("The surface area of the cylinder is: %lf\n", cylinderSurfaceAreaValue);
    printf("The surface area of the sphere is: %lf\n", sphereSurfaceAreaValue);
    printf("The surface area of the cone is: %lf\n", coneSurfaceAreaValue);

    return 0;
}