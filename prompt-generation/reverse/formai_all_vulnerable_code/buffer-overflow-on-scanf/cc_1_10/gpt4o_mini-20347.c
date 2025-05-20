//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function prototypes
float calculateCircleArea(float radius);
float calculateRectangleArea(float width, float height);
float calculateTriangleArea(float base, float height);
void displayMenu();

int main() {
    int choice;
    float radius, width, height, base;
    
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                printf("Area of the circle: %.2f\n", calculateCircleArea(radius));
                break;
            case 2:
                printf("Enter the width and height of the rectangle: ");
                scanf("%f %f", &width, &height);
                printf("Area of the rectangle: %.2f\n", calculateRectangleArea(width, height));
                break;
            case 3:
                printf("Enter the base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("Area of the triangle: %.2f\n", calculateTriangleArea(base, height));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

// Function to calculate area of a circle
float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

// Function to calculate area of a rectangle
float calculateRectangleArea(float width, float height) {
    return width * height;
}

// Function to calculate area of a triangle
float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

// Function to display menu
void displayMenu() {
    printf("\n--- Geometric Area Calculator ---\n");
    printf("1. Calculate Area of Circle\n");
    printf("2. Calculate Area of Rectangle\n");
    printf("3. Calculate Area of Triangle\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}