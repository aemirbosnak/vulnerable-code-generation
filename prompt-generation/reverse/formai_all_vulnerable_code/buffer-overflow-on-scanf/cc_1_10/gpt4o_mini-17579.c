//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

void displayMenu() {
    printf("Geometric Shapes Area Calculator\n");
    printf("1. Calculate Area of Triangle\n");
    printf("2. Calculate Area of Rectangle\n");
    printf("3. Calculate Area of Circle\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

float calculateRectangleArea(float length, float width) {
    return length * width;
}

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

void handleTriangle() {
    float base, height;
    printf("Enter base of the triangle: ");
    scanf("%f", &base);
    printf("Enter height of the triangle: ");
    scanf("%f", &height);
    float area = calculateTriangleArea(base, height);
    printf("Area of the Triangle: %.2f\n", area);
}

void handleRectangle() {
    float length, width;
    printf("Enter length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter width of the rectangle: ");
    scanf("%f", &width);
    float area = calculateRectangleArea(length, width);
    printf("Area of the Rectangle: %.2f\n", area);
}

void handleCircle() {
    float radius;
    printf("Enter radius of the circle: ");
    scanf("%f", &radius);
    float area = calculateCircleArea(radius);
    printf("Area of the Circle: %.2f\n", area);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                handleTriangle();
                break;
            case 2:
                handleRectangle();
                break;
            case 3:
                handleCircle();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }

        printf("\n"); // New line for better readability
    }

    return 0;
}