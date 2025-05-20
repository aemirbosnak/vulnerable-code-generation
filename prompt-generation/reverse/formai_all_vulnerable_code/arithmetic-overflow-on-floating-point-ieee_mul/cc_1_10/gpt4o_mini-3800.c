//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void calculateCircleArea();
void calculateRectangleArea();
void calculateTriangleArea();
void displayMenu();

int main() {
    int choice;
    
    while (1) {
        displayMenu();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Geometric Area Calculator ---\n");
    printf("1. Calculate Circle Area\n");
    printf("2. Calculate Rectangle Area\n");
    printf("3. Calculate Triangle Area\n");
    printf("4. Exit\n");
}

void calculateCircleArea() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    area = M_PI * radius * radius;
    printf("The area of the circle with radius %.2f is %.2f\n", radius, area);
}

void calculateRectangleArea() {
    float length, width, area;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    area = length * width;
    printf("The area of the rectangle with length %.2f and width %.2f is %.2f\n", length, width, area);
}

void calculateTriangleArea() {
    float base, height, area;
    printf("Enter the base of the triangle: ");
    scanf("%f", &base);
    printf("Enter the height of the triangle: ");
    scanf("%f", &height);

    area = 0.5 * base * height;
    printf("The area of the triangle with base %.2f and height %.2f is %.2f\n", base, height, area);
}