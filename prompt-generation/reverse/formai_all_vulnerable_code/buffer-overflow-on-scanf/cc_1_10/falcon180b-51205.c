//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the perimeter of a triangle
double calculateTrianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the circumference of a circle
double calculateCircleCircumference(double radius) {
    return 2 * 3.14159 * radius;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

int main() {
    double base, height, radius, length, width;
    double triangleArea, trianglePerimeter, circleArea, circleCircumference, rectangleArea, rectanglePerimeter;

    // Get input from user for triangle
    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &base, &height);

    // Calculate area and perimeter of triangle
    triangleArea = calculateTriangleArea(base, height);
    trianglePerimeter = calculateTrianglePerimeter(base, height, 0);

    // Print results for triangle
    printf("The area of the triangle is: %lf\n", triangleArea);
    printf("The perimeter of the triangle is: %lf\n", trianglePerimeter);

    // Get input from user for circle
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // Calculate area and circumference of circle
    circleArea = calculateCircleArea(radius);
    circleCircumference = calculateCircleCircumference(radius);

    // Print results for circle
    printf("The area of the circle is: %lf\n", circleArea);
    printf("The circumference of the circle is: %lf\n", circleCircumference);

    // Get input from user for rectangle
    printf("Enter the length and width of the rectangle: ");
    scanf("%lf %lf", &length, &width);

    // Calculate area and perimeter of rectangle
    rectangleArea = calculateRectangleArea(length, width);
    rectanglePerimeter = calculateRectanglePerimeter(length, width);

    // Print results for rectangle
    printf("The area of the rectangle is: %lf\n", rectangleArea);
    printf("The perimeter of the rectangle is: %lf\n", rectanglePerimeter);

    return 0;
}