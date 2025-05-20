//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

#define PI 3.14159

void calculateCircleArea() {
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = PI * radius * radius;
    printf("Area of the circle: %.2lf\n", area);
}

void calculateRectangleArea() {
    double length, width;
    printf("Enter the length and width of the rectangle: ");
    scanf("%lf %lf", &length, &width);
    double area = length * width;
    printf("Area of the rectangle: %.2lf\n", area);
}

void calculateTriangleArea() {
    double base, height;
    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &base, &height);
    double area = (base * height) / 2.0;
    printf("Area of the triangle: %.2lf\n", area);
}

void calculateSquareArea() {
    double side;
    printf("Enter the side length of the square: ");
    scanf("%lf", &side);
    double area = side * side;
    printf("Area of the square: %.2lf\n", area);
}

void displayMenu() {
    printf("\n--- Geometry Area Calculator ---\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Square\n");
    printf("5. Exit\n");
    printf("Choose a shape to calculate its area (1-5): ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateCircleArea();
                break;
            case 2:
                calculateRectangleArea();
                break;
            case 3:
                calculateTriangleArea();
                break;
            case 4:
                calculateSquareArea();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}