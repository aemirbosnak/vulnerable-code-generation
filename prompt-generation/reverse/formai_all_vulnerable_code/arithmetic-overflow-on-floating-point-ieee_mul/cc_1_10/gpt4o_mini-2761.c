//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void displayMenu() {
    printf("#######################\n");
    printf("#  Geometry Calculator #\n");
    printf("#######################\n");
    printf("1. Circle\n");
    printf("2. Triangle\n");
    printf("3. Rectangle\n");
    printf("4. Exit\n");
    printf("Choose a shape (1-4): ");
}

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

float calculateCirclePerimeter(float radius) {
    return 2 * PI * radius;
}

float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

float calculateTrianglePerimeter(float a, float b, float c) {
    return a + b + c;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

float calculateRectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

int main() {
    int choice;
    float radius, base, height, length, width, a, b, c;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("Area of Circle: %.2f\n", calculateCircleArea(radius));
                printf("Perimeter of Circle: %.2f\n\n", calculateCirclePerimeter(radius));
                break;
            case 2:
                printf("Enter base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("Area of Triangle: %.2f\n", calculateTriangleArea(base, height));
                printf("Enter lengths of the three sides (a, b, c): ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Perimeter of Triangle: %.2f\n\n", calculateTrianglePerimeter(a, b, c));
                break;
            case 3:
                printf("Enter length and width of the rectangle: ");
                scanf("%f %f", &length, &width);
                printf("Area of Rectangle: %.2f\n", calculateRectangleArea(length, width));
                printf("Perimeter of Rectangle: %.2f\n\n", calculateRectanglePerimeter(length, width));
                break;
            case 4:
                printf("Exiting the program. Have a geometrically fabulous day!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 4.\n\n");
                break;
        }
    }

    return 0;
}