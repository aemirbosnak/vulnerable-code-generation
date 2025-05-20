//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void displayMenu() {
    printf("Geometric Algorithm Menu:\n");
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

int main() {
    int choice;
    double radius, length, width, base, height, a, b, c;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Circle
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                printf("Circle Area: %.2lf\n", calculateCircleArea(radius));
                printf("Circle Perimeter: %.2lf\n", calculateCirclePerimeter(radius));
                break;
            case 2: // Rectangle
                printf("Enter the length of the rectangle: ");
                scanf("%lf", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%lf", &width);
                printf("Rectangle Area: %.2lf\n", calculateRectangleArea(length, width));
                printf("Rectangle Perimeter: %.2lf\n", calculateRectanglePerimeter(length, width));
                break;
            case 3: // Triangle
                printf("Enter the base of the triangle: ");
                scanf("%lf", &base);
                printf("Enter the height of the triangle: ");
                scanf("%lf", &height);
                printf("Area of the Triangle: %.2lf\n", calculateTriangleArea(base, height));
                printf("Enter the lengths of the sides of the triangle (a, b, c): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                printf("Triangle Perimeter: %.2lf\n", calculateTrianglePerimeter(a, b, c));
                break;
            case 4: // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}