//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define mathematical functions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

// Define a function to calculate the area of a circle
float area_circle(float radius) {
    return 3.14159 * radius * radius;
}

// Define a function to calculate the volume of a sphere
float volume_sphere(float radius) {
    return (4/3) * 3.14159 * radius * radius * radius;
}

int main() {
    // Declare variables
    float radius, area, volume;

    // Ask user for radius
    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    // Calculate area of circle
    area = area_circle(radius);
    printf("Area of circle = %f\n", area);

    // Calculate volume of sphere
    volume = volume_sphere(radius);
    printf("Volume of sphere = %f\n", volume);

    // Calculate surface area of sphere
    float surface_area = 4 * 3.14159 * radius * radius;
    printf("Surface area of sphere = %f\n", surface_area);

    return 0;
}