//Code Llama-13B DATASET v1.0 Category: Geometric algorithms ; Style: surprised
// Geometric algorithms example program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the area of a triangle
float triangleArea(float base, float height) {
    return (base * height) / 2;
}

// Function to calculate the area of a rectangle
float rectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the area of a circle
float circleArea(float radius) {
    return 3.14 * radius * radius;
}

// Function to calculate the area of a square
float squareArea(float side) {
    return side * side;
}

int main() {
    float base, height, length, width, radius, side;

    // Calculate the area of a triangle
    printf("Enter the base and height of the triangle: ");
    scanf("%f %f", &base, &height);
    printf("The area of the triangle is: %.2f\n", triangleArea(base, height));

    // Calculate the area of a rectangle
    printf("Enter the length and width of the rectangle: ");
    scanf("%f %f", &length, &width);
    printf("The area of the rectangle is: %.2f\n", rectangleArea(length, width));

    // Calculate the area of a circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    printf("The area of the circle is: %.2f\n", circleArea(radius));

    // Calculate the area of a square
    printf("Enter the side of the square: ");
    scanf("%f", &side);
    printf("The area of the square is: %.2f\n", squareArea(side));

    return 0;
}