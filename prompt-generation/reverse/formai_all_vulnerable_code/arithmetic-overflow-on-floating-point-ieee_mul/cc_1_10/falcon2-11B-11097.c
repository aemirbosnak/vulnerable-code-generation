//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include <stdio.h>
#include <math.h>

// Define a function to calculate the area of a triangle
double calculateArea(double base, double height) {
    return 0.5 * base * height;
}

// Define a function to calculate the perimeter of a rectangle
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Define a function to calculate the area of a square
double calculateSquareArea(double side) {
    return side * side;
}

// Define a function to calculate the circumference of a circle
double calculateCircumference(double radius) {
    return 2 * M_PI * radius;
}

// Define a function to calculate the volume of a sphere
double calculateSphereVolume(double radius) {
    return (4.0/3.0) * M_PI * radius * radius * radius;
}

int main() {
    // Prompt the user for input
    printf("Enter the base and height of a triangle: ");
    double base, height;
    scanf("%lf %lf", &base, &height);
    
    // Calculate the area of the triangle
    double triangleArea = calculateArea(base, height);
    
    // Calculate the perimeter of a rectangle
    double rectangleLength, rectangleWidth;
    printf("Enter the length and width of a rectangle: ");
    scanf("%lf %lf", &rectangleLength, &rectangleWidth);
    double rectanglePerimeter = calculatePerimeter(rectangleLength, rectangleWidth);
    
    // Calculate the area of a square
    double squareSide;
    printf("Enter the side length of a square: ");
    scanf("%lf", &squareSide);
    double squareArea = calculateSquareArea(squareSide);
    
    // Calculate the circumference of a circle
    double circleRadius;
    printf("Enter the radius of a circle: ");
    scanf("%lf", &circleRadius);
    double circleCircumference = calculateCircumference(circleRadius);
    
    // Calculate the volume of a sphere
    double sphereRadius;
    printf("Enter the radius of a sphere: ");
    scanf("%lf", &sphereRadius);
    double sphereVolume = calculateSphereVolume(sphereRadius);
    
    // Print the results
    printf("Triangle Area: %.2lf\n", triangleArea);
    printf("Rectangle Perimeter: %.2lf\n", rectanglePerimeter);
    printf("Square Area: %.2lf\n", squareArea);
    printf("Circle Circumference: %.2lf\n", circleCircumference);
    printf("Sphere Volume: %.2lf\n", sphereVolume);
    
    return 0;
}