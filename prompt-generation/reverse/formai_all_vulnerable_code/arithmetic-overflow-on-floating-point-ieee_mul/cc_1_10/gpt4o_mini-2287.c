//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// Function prototypes
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);

int main() {
    int choice;
    double radius, length, width, base, height, area;

    do {
        // Display menu
        printf("\nGeometric Area Calculator\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Circle
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                area = calculateCircleArea(radius);
                printf("Area of the circle: %.2lf\n", area);
                break;

            case 2:
                // Rectangle
                printf("Enter the length of the rectangle: ");
                scanf("%lf", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%lf", &width);
                area = calculateRectangleArea(length, width);
                printf("Area of the rectangle: %.2lf\n", area);
                break;

            case 3:
                // Triangle
                printf("Enter the base of the triangle: ");
                scanf("%lf", &base);
                printf("Enter the height of the triangle: ");
                scanf("%lf", &height);
                area = calculateTriangleArea(base, height);
                printf("Area of the triangle: %.2lf\n", area);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return M_PI * radius * radius; // Area = π * r^2
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width; // Area = length * width
}

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height; // Area = 1/2 * base * height
}