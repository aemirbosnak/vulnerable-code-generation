//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void displayMenu() {
    printf("\n--- Area Calculation Menu ---\n");
    printf("1. Calculate Area of Circle\n");
    printf("2. Calculate Area of Rectangle\n");
    printf("3. Calculate Area of Triangle\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Please enter your choice: ");
}

double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

void calculateArea(int choice) {
    double area;

    switch (choice) {
        case 1: {
            double radius;
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            area = calculateCircleArea(radius);
            printf("Area of Circle: %.2f\n", area);
            break;
        }
        case 2: {
            double length, width;
            printf("Enter the length and width of the rectangle: ");
            scanf("%lf %lf", &length, &width);
            area = calculateRectangleArea(length, width);
            printf("Area of Rectangle: %.2f\n", area);
            break;
        }
        case 3: {
            double base, height;
            printf("Enter the base and height of the triangle: ");
            scanf("%lf %lf", &base, &height);
            area = calculateTriangleArea(base, height);
            printf("Area of Triangle: %.2f\n", area);
            break;
        }
        case 4:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        calculateArea(choice);
    }

    return 0;
}