//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
This program calculates the area and perimeter of different geometrical shapes: triangle, square and circle.
*/

void triangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    float perimeter = a + b + c;

    printf("Triangle:\n");
    printf("Area = %.2f \n", area);
    printf("Perimeter = %.2f \n", perimeter);
}

void square(float a) {
    float area = a * a;
    float perimeter = 4 * a;

    printf("Square:\n");
    printf("Area = %.2f \n", area);
    printf("Perimeter = %.2f \n", perimeter);
}

void circle(float r) {
    float area = M_PI * r * r;
    float perimeter = 2 * M_PI * r;

    printf("Circle:\n");
    printf("Area = %.2f \n", area);
    printf("Perimeter = %.2f \n", perimeter);
}

int main() {
    int shape;
    float a, b, c, r;

    printf("Choose a shape to calculate the area and perimeter:\n");
    printf("1. Triangle\n");
    printf("2. Square\n");
    printf("3. Circle\n");
    printf("Enter your choice: ");
    scanf("%d", &shape);

    switch (shape) {
        case 1:
            printf("Enter the length of three sides of triangle: ");
            scanf("%f %f %f", &a, &b, &c);
            triangle(a, b, c);
            break;
        case 2:
            printf("Enter the length of one side of square: ");
            scanf("%f", &a);
            square(a);
            break;
        case 3:
            printf("Enter the radius of circle: ");
            scanf("%f", &r);
            circle(r);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}