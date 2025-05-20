//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct definitions for different geometric shapes
typedef struct {
    double radius;
} Circle;

typedef struct {
    double length;
    double width;
} Rectangle;

typedef struct {
    double base;
    double height;
} Triangle;

// Function prototypes
double calculateCircleArea(Circle circle);
double calculateRectangleArea(Rectangle rectangle);
double calculateTriangleArea(Triangle triangle);
void displayMenu();

// Main function
int main() {
    int choice;
    double area = 0.0;

    while (1) {
        displayMenu();
        printf("Pick a shape to calculate the area (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Circle circle;
                printf("Enter the radius of the circle: ");
                scanf("%lf", &circle.radius);
                area = calculateCircleArea(circle);
                printf("The area of the circle is: %.2f\n", area);
                break;
            }
            case 2: {
                Rectangle rectangle;
                printf("Enter the length and width of the rectangle: ");
                scanf("%lf %lf", &rectangle.length, &rectangle.width);
                area = calculateRectangleArea(rectangle);
                printf("The area of the rectangle is: %.2f\n", area);
                break;
            }
            case 3: {
                Triangle triangle;
                printf("Enter the base and height of the triangle: ");
                scanf("%lf %lf", &triangle.base, &triangle.height);
                area = calculateTriangleArea(triangle);
                printf("The area of the triangle is: %.2f\n", area);
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

// Function to calculate area of a circle
double calculateCircleArea(Circle circle) {
    return M_PI * circle.radius * circle.radius;
}

// Function to calculate area of a rectangle
double calculateRectangleArea(Rectangle rectangle) {
    return rectangle.length * rectangle.width;
}

// Function to calculate area of a triangle
double calculateTriangleArea(Triangle triangle) {
    return 0.5 * triangle.base * triangle.height;
}

// Function to display the menu
void displayMenu() {
    printf("=== Area Calculator ===\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
}