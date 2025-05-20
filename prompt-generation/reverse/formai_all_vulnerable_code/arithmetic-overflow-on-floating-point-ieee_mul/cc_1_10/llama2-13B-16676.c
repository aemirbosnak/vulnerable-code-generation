//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to calculate the area of a circle
double circleArea(double radius) {
    return 3.14159 * radius * radius;
}

// Define a function to calculate the circumference of a circle
double circleCircumference(double radius) {
    return 2 * 3.14159 * radius;
}

// Define a function to calculate the volume of a sphere
double sphereVolume(double radius) {
    return (4/3) * 3.14159 * radius * radius * radius;
}

// Define a function to calculate the surface area of a sphere
double sphereSurfaceArea(double radius) {
    return 4 * 3.14159 * radius * radius;
}

int main() {
    // Ask the user for the radius of the circle
    printf("Enter the radius of the circle: ");
    double radius;
    scanf("%lf", &radius);

    // Calculate and display the area of the circle
    double area = circleArea(radius);
    printf("The area of the circle is: %f\n", area);

    // Calculate and display the circumference of the circle
    double circumference = circleCircumference(radius);
    printf("The circumference of the circle is: %f\n", circumference);

    // Ask the user if they want to calculate the volume or surface area of a sphere
    printf("Do you want to calculate the volume or surface area of a sphere? (V/S): ");
    char choice;
    scanf(" %c", &choice);

    // Based on the user's input, calculate and display the appropriate value
    if (choice == 'V') {
        // Calculate and display the volume of the sphere
        double volume = sphereVolume(radius);
        printf("The volume of the sphere is: %f\n", volume);
    } else if (choice == 'S') {
        // Calculate and display the surface area of the sphere
        double surfaceArea = sphereSurfaceArea(radius);
        printf("The surface area of the sphere is: %f\n", surfaceArea);
    } else {
        printf("Invalid input. Please enter 'V' for volume or 'S' for surface area.\n");
    }

    return 0;
}