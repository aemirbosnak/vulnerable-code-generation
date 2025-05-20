//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void displayMenu() {
    printf("Geometric Area and Perimeter Calculator\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateCirclePerimeter(double radius) {
    return 2 * PI * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateTrianglePerimeter(double a, double b, double c) {
    return a + b + c;
}

double getPositiveInput(char *prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) != 1 || value <= 0) {
            printf("Invalid input, please enter a positive number.\n");
            while (getchar() != '\n'); // Clear the invalid input
        } else {
            break;
        }
    }
    return value;
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Circle
                double radius = getPositiveInput("Enter the radius of the circle: ");
                printf("Circle Area: %.2f\n", calculateCircleArea(radius));
                printf("Circle Perimeter: %.2f\n", calculateCirclePerimeter(radius));
                break;
            }
            case 2: { // Rectangle
                double length = getPositiveInput("Enter the length of the rectangle: ");
                double width = getPositiveInput("Enter the width of the rectangle: ");
                printf("Rectangle Area: %.2f\n", calculateRectangleArea(length, width));
                printf("Rectangle Perimeter: %.2f\n", calculateRectanglePerimeter(length, width));
                break;
            }
            case 3: { // Triangle
                double base = getPositiveInput("Enter the base of the triangle: ");
                double height = getPositiveInput("Enter the height of the triangle: ");
                double side1 = getPositiveInput("Enter the length of the first side of the triangle: ");
                double side2 = getPositiveInput("Enter the length of the second side of the triangle: ");
                double side3 = getPositiveInput("Enter the length of the third side of the triangle: ");
                printf("Triangle Area: %.2f\n", calculateTriangleArea(base, height));
                printf("Triangle Perimeter: %.2f\n", calculateTrianglePerimeter(side1, side2, side3));
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}