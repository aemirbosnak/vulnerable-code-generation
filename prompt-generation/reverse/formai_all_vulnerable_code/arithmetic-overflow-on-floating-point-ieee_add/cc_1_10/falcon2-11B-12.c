//Falcon2-11B DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>
#include <math.h>

// Funny function to calculate the area of a rectangle
float funnyArea(float length, float width) {
    if (length == 0 || width == 0) {
        printf("Error: length and width cannot be zero!\n");
        return -1;
    }
    return length * width;
}

// Funny function to calculate the perimeter of a rectangle
float funnyPerimeter(float length, float width) {
    if (length == 0 || width == 0) {
        printf("Error: length and width cannot be zero!\n");
        return -1;
    }
    return 2 * (length + width);
}

// Funny function to calculate the area of a triangle
float funnyAreaTriangle(float base, float height) {
    if (base == 0 || height == 0) {
        printf("Error: base and height cannot be zero!\n");
        return -1;
    }
    return 0.5 * base * height;
}

// Funny function to calculate the area of a circle
float funnyAreaCircle(float radius) {
    if (radius == 0) {
        printf("Error: radius cannot be zero!\n");
        return -1;
    }
    return M_PI * radius * radius;
}

// Funny function to calculate the perimeter of a circle
float funnyPerimeterCircle(float radius) {
    if (radius == 0) {
        printf("Error: radius cannot be zero!\n");
        return -1;
    }
    return 2 * M_PI * radius;
}

int main() {
    float length, width, base, height, radius;
    printf("Enter the length and width of a rectangle: ");
    scanf("%f %f", &length, &width);
    float area = funnyArea(length, width);
    float perimeter = funnyPerimeter(length, width);
    printf("The area of the rectangle is %f and the perimeter is %f\n", area, perimeter);

    printf("Enter the base and height of a triangle: ");
    scanf("%f %f", &base, &height);
    float areaTriangle = funnyAreaTriangle(base, height);
    printf("The area of the triangle is %f\n", areaTriangle);

    printf("Enter the radius of a circle: ");
    scanf("%f", &radius);
    float areaCircle = funnyAreaCircle(radius);
    float perimeterCircle = funnyPerimeterCircle(radius);
    printf("The area of the circle is %f and the perimeter is %f\n", areaCircle, perimeterCircle);

    return 0;
}