//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

// Function prototypes
void calculateCircleArea();
void calculateRectangleArea();
void calculateTriangleArea();
void calculateTrapezoidArea();
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
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
                calculateTrapezoidArea();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

// Function to calculate the area of a circle
void calculateCircleArea() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area = M_PI * radius * radius; // Area = πr^2
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);
}

// Function to calculate the area of a rectangle
void calculateRectangleArea() {
    float length, width, area;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);
    area = length * width; // Area = l * w
    printf("The area of the rectangle with length %.2f and width %.2f is %.2f\n", length, width, area);
}

// Function to calculate the area of a triangle
void calculateTriangleArea() {
    float base, height, area;
    printf("Enter the base of the triangle: ");
    scanf("%f", &base);
    printf("Enter the height of the triangle: ");
    scanf("%f", &height);
    area = 0.5 * base * height; // Area = 1/2 * b * h
    printf("The area of the triangle with base %.2f and height %.2f is %.2f\n", base, height, area);
}

// Function to calculate the area of a trapezoid
void calculateTrapezoidArea() {
    float base1, base2, height, area;
    printf("Enter the length of the first base of the trapezoid: ");
    scanf("%f", &base1);
    printf("Enter the length of the second base of the trapezoid: ");
    scanf("%f", &base2);
    printf("Enter the height of the trapezoid: ");
    scanf("%f", &height);
    area = 0.5 * (base1 + base2) * height; // Area = 1/2 * (b1 + b2) * h
    printf("The area of the trapezoid with bases %.2f and %.2f, and height %.2f is %.2f\n", base1, base2, height, area);
}

// Function to show the menu of options
void showMenu() {
    printf("----- Area Calculator -----\n");
    printf("1. Calculate area of a Circle\n");
    printf("2. Calculate area of a Rectangle\n");
    printf("3. Calculate area of a Triangle\n");
    printf("4. Calculate area of a Trapezoid\n");
    printf("5. Exit\n");
}