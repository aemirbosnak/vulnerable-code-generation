//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Shape Shifting program!\n");
    printf("Enter the shape you want to transform: \n");
    printf("1. Square\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");

    int shape;
    scanf("%d", &shape);

    if (shape == 1) {
        printf("Enter the side length of the square: ");
        int side;
        scanf("%d", &side);
        int area = side * side;
        printf("The area of the square is: %d\n", area);
        printf("Enter the new side length for the square: ");
        int newSide;
        scanf("%d", &newSide);
        int newArea = newSide * newSide;
        printf("The new area of the square is: %d\n", newArea);
    } else if (shape == 2) {
        printf("Enter the radius of the circle: ");
        float radius;
        scanf("%f", &radius);
        float area = 3.14 * radius * radius;
        printf("The area of the circle is: %f\n", area);
        printf("Enter the new radius for the circle: ");
        float newRadius;
        scanf("%f", &newRadius);
        float newArea = 3.14 * newRadius * newRadius;
        printf("The new area of the circle is: %f\n", newArea);
    } else if (shape == 3) {
        printf("Enter the base length of the triangle: ");
        int base;
        scanf("%d", &base);
        printf("Enter the height of the triangle: ");
        int height;
        scanf("%d", &height);
        float area = 0.5 * base * height;
        printf("The area of the triangle is: %f\n", area);
        printf("Enter the new base length for the triangle: ");
        int newBase;
        scanf("%d", &newBase);
        printf("Enter the new height for the triangle: ");
        int newHeight;
        scanf("%d", &newHeight);
        float newArea = 0.5 * newBase * newHeight;
        printf("The new area of the triangle is: %f\n", newArea);
    }

    return 0;
}