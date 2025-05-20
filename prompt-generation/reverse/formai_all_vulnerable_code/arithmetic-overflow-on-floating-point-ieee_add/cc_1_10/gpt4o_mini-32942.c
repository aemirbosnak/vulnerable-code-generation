//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function Prototypes
void calcCircle();
void calcRectangle();
void calcTriangle();
double circleArea(double radius);
double circlePerimeter(double radius);
double rectangleArea(double length, double width);
double rectanglePerimeter(double length, double width);
double triangleArea(double base, double height);
double trianglePerimeter(double a, double b, double c);
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                calcCircle();
                break;
            case 2:
                calcRectangle();
                break;
            case 3:
                calcTriangle();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nGeometric Algorithms Menu:\n");
    printf("1. Calculate Circle Area and Perimeter\n");
    printf("2. Calculate Rectangle Area and Perimeter\n");
    printf("3. Calculate Triangle Area and Perimeter\n");
    printf("4. Exit\n");
}

void calcCircle() {
    double radius;
    
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    if (radius < 0) {
        printf("Radius cannot be negative. Please enter a valid value.\n");
        return;
    }

    double area = circleArea(radius);
    double perimeter = circlePerimeter(radius);

    printf("Circle Area: %.2lf\n", area);
    printf("Circle Perimeter (Circumference): %.2lf\n", perimeter);
}

void calcRectangle() {
    double length, width;

    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    if (length < 0 || width < 0) {
        printf("Length and width cannot be negative. Please enter valid values.\n");
        return;
    }

    double area = rectangleArea(length, width);
    double perimeter = rectanglePerimeter(length, width);

    printf("Rectangle Area: %.2lf\n", area);
    printf("Rectangle Perimeter: %.2lf\n", perimeter);
}

void calcTriangle() {
    double a, b, c, base, height;

    printf("Enter the length of side a of the triangle: ");
    scanf("%lf", &a);
    printf("Enter the length of side b of the triangle: ");
    scanf("%lf", &b);
    printf("Enter the length of side c of the triangle: ");
    scanf("%lf", &c);

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("All sides must be positive values. Please enter valid values.\n");
        return;
    }
    
    // Calculate perimeter
    double perimeter = trianglePerimeter(a, b, c);
    
    // Assume base is side a and calculate height using Heron's formula for area
    double semiPerimeter = perimeter / 2;
    double area = sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    
    printf("Triangle Area: %.2lf\n", area);
    printf("Triangle Perimeter: %.2lf\n", perimeter);
}

double circleArea(double radius) {
    return PI * radius * radius;
}

double circlePerimeter(double radius) {
    return 2 * PI * radius;
}

double rectangleArea(double length, double width) {
    return length * width;
}

double rectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

double triangleArea(double base, double height) {
    return (base * height) / 2;
}

double trianglePerimeter(double a, double b, double c) {
    return a + b + c;
}