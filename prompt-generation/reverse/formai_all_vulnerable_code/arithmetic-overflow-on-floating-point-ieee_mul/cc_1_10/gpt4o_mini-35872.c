//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Struct definitions for different shapes
typedef struct {
    float radius;
} Circle;

typedef struct {
    float width;
    float height;
} Rectangle;

typedef struct {
    float base;
    float height;
} Triangle;

// Function prototypes
float calculateCircleArea(Circle circle);
float calculateRectangleArea(Rectangle rectangle);
float calculateTriangleArea(Triangle triangle);
void displayMenu();

int main() {
    int choice;
    float area = 0.0;

    // Main program loop
    do {
        displayMenu();
        printf("Choose a shape to calculate the area (1-3) or 0 to exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { // Circle
                Circle circle;
                printf("Enter the radius of the circle: ");
                scanf("%f", &circle.radius);
                area = calculateCircleArea(circle);
                printf("The area of the circle is: %.2f\n", area);
                break;
            }
            case 2: { // Rectangle
                Rectangle rectangle;
                printf("Enter the width of the rectangle: ");
                scanf("%f", &rectangle.width);
                printf("Enter the height of the rectangle: ");
                scanf("%f", &rectangle.height);
                area = calculateRectangleArea(rectangle);
                printf("The area of the rectangle is: %.2f\n", area);
                break;
            }
            case 3: { // Triangle
                Triangle triangle;
                printf("Enter the base of the triangle: ");
                scanf("%f", &triangle.base);
                printf("Enter the height of the triangle: ");
                scanf("%f", &triangle.height);
                area = calculateTriangleArea(triangle);
                printf("The area of the triangle is: %.2f\n", area);
                break;
            }
            case 0: // Exit
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}

// Function to calculate the area of a circle
float calculateCircleArea(Circle circle) {
    return PI * circle.radius * circle.radius;
}

// Function to calculate the area of a rectangle
float calculateRectangleArea(Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}

// Function to calculate the area of a triangle
float calculateTriangleArea(Triangle triangle) {
    return 0.5 * triangle.base * triangle.height;
}

// Function to display menu options
void displayMenu() {
    printf("\n--- Area Calculator ---\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("0. Exit\n");
}