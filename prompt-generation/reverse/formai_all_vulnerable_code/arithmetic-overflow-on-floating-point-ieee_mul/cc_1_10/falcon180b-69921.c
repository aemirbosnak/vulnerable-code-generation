//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a circle
double circle_area(double radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the perimeter of a circle
double circle_perimeter(double radius) {
    return 2 * 3.14159 * radius;
}

// Function to calculate the area of a rectangle
double rectangle_area(double length, double width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
double rectangle_perimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the area of a triangle
double triangle_area(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the perimeter of a triangle
double triangle_perimeter(double base, double height) {
    return base + (2 * sqrt(pow(base, 2) + pow(height, 2)));
}

int main() {
    // Test circle functions
    double circle_radius = 5.0;
    printf("Circle area: %.2f\n", circle_area(circle_radius));
    printf("Circle perimeter: %.2f\n", circle_perimeter(circle_radius));

    // Test rectangle functions
    double rectangle_length = 10.0;
    double rectangle_width = 8.0;
    printf("Rectangle area: %.2f\n", rectangle_area(rectangle_length, rectangle_width));
    printf("Rectangle perimeter: %.2f\n", rectangle_perimeter(rectangle_length, rectangle_width));

    // Test triangle functions
    double triangle_base = 12.0;
    double triangle_height = 9.0;
    printf("Triangle area: %.2f\n", triangle_area(triangle_base, triangle_height));
    printf("Triangle perimeter: %.2f\n", triangle_perimeter(triangle_base, triangle_height));

    return 0;
}