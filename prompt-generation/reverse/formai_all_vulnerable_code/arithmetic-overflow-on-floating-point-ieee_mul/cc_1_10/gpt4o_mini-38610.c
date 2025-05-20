//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Function prototypes
void calculateCircleArea();
void calculateTriangleArea();
void calculateRectangleArea();
void displayMenu();

int main() {
    int choice = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateCircleArea();
                break;
            case 2:
                calculateTriangleArea();
                break;
            case 3:
                calculateRectangleArea();
                break;
            case 4:
                printf("Thank you for using the Geometric Area Calculator! Goodbye! 🎉\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=====================\n");
    printf("Geometric Area Calculator\n");
    printf("=====================\n");
    printf("1. Calculate Area of Circle\n");
    printf("2. Calculate Area of Triangle\n");
    printf("3. Calculate Area of Rectangle\n");
    printf("4. Exit\n");
    printf("=====================\n");
}

void calculateCircleArea() {
    double radius, area;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    if (radius < 0) {
        printf("Radius cannot be negative! Please try again.\n");
        return;
    }

    area = PI * radius * radius;
    printf("The area of the circle with radius %.2f is: %.2f\n", radius, area);
}

void calculateTriangleArea() {
    double base, height, area;

    printf("Enter the base of the triangle: ");
    scanf("%lf", &base);
    printf("Enter the height of the triangle: ");
    scanf("%lf", &height);

    if (base < 0 || height < 0) {
        printf("Base and height cannot be negative! Please try again.\n");
        return;
    }

    area = 0.5 * base * height;
    printf("The area of the triangle with base %.2f and height %.2f is: %.2f\n", base, height, area);
}

void calculateRectangleArea() {
    double length, width, area;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    if (length < 0 || width < 0) {
        printf("Length and width cannot be negative! Please try again.\n");
        return;
    }

    area = length * width;
    printf("The area of the rectangle with length %.2f and width %.2f is: %.2f\n", length, width, area);
}