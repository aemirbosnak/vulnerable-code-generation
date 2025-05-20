//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
float calculateTriangleArea(float base, float height);
float calculateRectangleArea(float length, float width);
float calculateCircleArea(float radius);

int main() {
    int choice;
    float base, height, length, width, radius;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter base of the triangle: ");
                scanf("%f", &base);
                printf("Enter height of the triangle: ");
                scanf("%f", &height);
                printf("Area of the triangle: %.2f\n", calculateTriangleArea(base, height));
                break;
            case 2:
                printf("Enter length of the rectangle: ");
                scanf("%f", &length);
                printf("Enter width of the rectangle: ");
                scanf("%f", &width);
                printf("Area of the rectangle: %.2f\n", calculateRectangleArea(length, width));
                break;
            case 3:
                printf("Enter radius of the circle: ");
                scanf("%f", &radius);
                printf("Area of the circle: %.2f\n", calculateCircleArea(radius));
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");  // Just for spacing
    }
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("----------- Area Calculator -----------\n");
    printf("1. Calculate area of Triangle\n");
    printf("2. Calculate area of Rectangle\n");
    printf("3. Calculate area of Circle\n");
    printf("4. Exit\n");
    printf("--------------------------------------\n");
}

// Function to calculate the area of a triangle
float calculateTriangleArea(float base, float height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return M_PI * radius * radius;
}