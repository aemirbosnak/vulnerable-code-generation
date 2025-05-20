//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculateAreaOfCircle(double radius);
double calculateCircumference(double radius);
double calculateAreaOfRectangle(double length, double width);
double calculatePerimeterOfRectangle(double length, double width);
double calculateAreaOfTriangle(double base, double height);
double calculatePerimeterOfTriangle(double sideA, double sideB, double sideC);
void displayMenu();
void handleCircle();
void handleRectangle();
void handleTriangle();

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Choose a shape (1-3) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            case 1:
                handleCircle();
                break;
            case 2:
                handleRectangle();
                break;
            case 3:
                handleTriangle();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n==== Geometry Calculator ====\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("0. Exit\n");
}

void handleCircle() {
    double radius;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    double area = calculateAreaOfCircle(radius);
    double circumference = calculateCircumference(radius);

    printf("Circle with radius %.2f:\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);
}

double calculateAreaOfCircle(double radius) {
    return M_PI * radius * radius;
}

double calculateCircumference(double radius) {
    return 2 * M_PI * radius;
}

void handleRectangle() {
    double length, width;

    printf("Enter the length and width of the rectangle: ");
    scanf("%lf %lf", &length, &width);

    double area = calculateAreaOfRectangle(length, width);
    double perimeter = calculatePerimeterOfRectangle(length, width);

    printf("Rectangle with length %.2f and width %.2f:\n", length, width);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}

double calculateAreaOfRectangle(double length, double width) {
    return length * width;
}

double calculatePerimeterOfRectangle(double length, double width) {
    return 2 * (length + width);
}

void handleTriangle() {
    double base, height, sideA, sideB, sideC;

    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &base, &height);
    printf("Enter the lengths of the three sides: ");
    scanf("%lf %lf %lf", &sideA, &sideB, &sideC);

    double area = calculateAreaOfTriangle(base, height);
    double perimeter = calculatePerimeterOfTriangle(sideA, sideB, sideC);

    printf("Triangle with base %.2f and height %.2f:\n", base, height);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);
}

double calculateAreaOfTriangle(double base, double height) {
    return 0.5 * base * height;
}

double calculatePerimeterOfTriangle(double sideA, double sideB, double sideC) {
    return sideA + sideB + sideC;
}