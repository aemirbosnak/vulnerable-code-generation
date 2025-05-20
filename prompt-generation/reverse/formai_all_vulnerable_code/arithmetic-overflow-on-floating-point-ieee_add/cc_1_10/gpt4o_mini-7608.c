//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void printMenu() {
    printf("Choose a shape to calculate:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Rectangle\n");
    printf("4. Triangle\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateCircleCircumference(double radius) {
    return 2 * PI * radius;
}

double calculateSquareArea(double side) {
    return side * side;
}

double calculateSquarePerimeter(double side) {
    return 4 * side;
}

double calculateRectangleArea(double width, double height) {
    return width * height;
}

double calculateRectanglePerimeter(double width, double height) {
    return 2 * (width + height);
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

int main() {
    int choice;
    double radius, side, width, height, base, a, b, c;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                printf("Circle Area: %.2f\n", calculateCircleArea(radius));
                printf("Circle Circumference: %.2f\n", calculateCircleCircumference(radius));
                break;
            case 2:
                printf("Enter the side length of the square: ");
                scanf("%lf", &side);
                printf("Square Area: %.2f\n", calculateSquareArea(side));
                printf("Square Perimeter: %.2f\n", calculateSquarePerimeter(side));
                break;
            case 3:
                printf("Enter the width and height of the rectangle: ");
                scanf("%lf %lf", &width, &height);
                printf("Rectangle Area: %.2f\n", calculateRectangleArea(width, height));
                printf("Rectangle Perimeter: %.2f\n", calculateRectanglePerimeter(width, height));
                break;
            case 4:
                printf("Enter the base and height of the triangle: ");
                scanf("%lf %lf", &base, &height);
                printf("Triangle Area: %.2f\n", calculateTriangleArea(base, height));
                
                printf("Enter the lengths of all three sides of the triangle for perimeter calculation: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                printf("Triangle Perimeter: %.2f\n", calculateTrianglePerimeter(a, b, c));
                break;
            case 5:
                printf("Thank you for using the Geometric Calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}