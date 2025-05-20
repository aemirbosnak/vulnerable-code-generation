//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <math.h>

// function to calculate the area of a circle
float areaOfCircle(float radius) {
    return 3.14159 * radius * radius;
}

// function to calculate the perimeter of a circle
float perimeterOfCircle(float radius) {
    return 2 * 3.14159 * radius;
}

// function to calculate the area of a rectangle
float areaOfRectangle(float length, float width) {
    return length * width;
}

// function to calculate the perimeter of a rectangle
float perimeterOfRectangle(float length, float width) {
    return 2 * (length + width);
}

// function to calculate the area of a triangle
float areaOfTriangle(float base, float height) {
    return 0.5 * base * height;
}

// function to calculate the perimeter of a triangle
float perimeterOfTriangle(float base, float height) {
    return base + 2 * sqrt(pow(height, 2) + pow(base, 2));
}

int main() {
    // example usage of the functions
    float radius = 5.0;
    float length = 10.0;
    float width = 5.0;
    float base = 10.0;
    float height = 5.0;

    printf("Area of circle with radius %f: %f\n", radius, areaOfCircle(radius));
    printf("Perimeter of circle with radius %f: %f\n", radius, perimeterOfCircle(radius));

    printf("Area of rectangle with length %f and width %f: %f\n", length, width, areaOfRectangle(length, width));
    printf("Perimeter of rectangle with length %f and width %f: %f\n", length, width, perimeterOfRectangle(length, width));

    printf("Area of triangle with base %f and height %f: %f\n", base, height, areaOfTriangle(base, height));
    printf("Perimeter of triangle with base %f and height %f: %f\n", base, height, perimeterOfTriangle(base, height));

    return 0;
}