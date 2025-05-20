//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawCircle(int radius) {
    printf("Drawing a Circle with radius %d:\n", radius);
    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawSquare(int side) {
    printf("Drawing a Square with side %d:\n", side);
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void drawTriangle(int height) {
    printf("Drawing a Triangle of height %d:\n", height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void shapeTransform(char shape, float value) {
    switch (shape) {
        case 'c': // Circle transformation
            drawCircle((int)value);
            break;
        case 's': // Square transformation
            drawSquare((int)value);
            break;
        case 't': // Triangle transformation
            drawTriangle((int)value);
            break;
        default:
            printf("Invalid shape! Please use 'c' for Circle, 's' for Square, or 't' for Triangle.\n");
            break;
    }
}

int main() {
    char shape;
    float value;

    printf("Enter a shape (c for Circle, s for Square, t for Triangle): ");
    scanf(" %c", &shape);
    
    printf("Enter the size (radius for Circle, side for Square, height for Triangle): ");
    scanf("%f", &value);
    
    printf("\nShape Transformation:\n");
    shapeTransform(shape, value);

    printf("\nMathematical Transformations:\n");
    switch (shape) {
        case 'c':
            printf("Area of Circle = π * r^2 \n");
            printf("Circumference of Circle = 2 * π * r \n");
            printf("Calculated Area: %.2f\n", M_PI * value * value);
            printf("Calculated Circumference: %.2f\n", 2 * M_PI * value);
            break;
        case 's':
            printf("Area of Square = side^2 \n");
            printf("Perimeter of Square = 4 * side \n");
            printf("Calculated Area: %.2f\n", value * value);
            printf("Calculated Perimeter: %.2f\n", 4 * value);
            break;
        case 't':
            printf("Area of Triangle = (base * height) / 2 \n");
            printf("Considering base equal to height in calculations.\n");
            printf("Calculated Area: %.2f\n", (value * value) / 2);
            printf("Perimeter (approx. as an equilateral triangle) = 3 * side\n");
            printf("Calculated Perimeter: %.2f\n", 3 * value);
            break;
        default:
            break;
    }

    return 0;
}