//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// Structure to hold the shape data
typedef struct {
    char shapeType[20];
    double area;
} Shape;

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Function to display the result
void displayArea(Shape shape) {
    printf("The area of the %s is: %.2f\n", shape.shapeType, shape.area);
}

// Main function
int main() {
    int choice;
    Shape *shape = (Shape*)malloc(sizeof(Shape));

    if (shape == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Geometric Area Calculator\n");
    printf("Select a shape to calculate area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            double radius;
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            shape->area = calculateCircleArea(radius);
            snprintf(shape->shapeType, sizeof(shape->shapeType), "Circle");
            displayArea(*shape);
            break;
        }
        case 2: {
            double length, width;
            printf("Enter the length and width of the rectangle: ");
            scanf("%lf %lf", &length, &width);
            shape->area = calculateRectangleArea(length, width);
            snprintf(shape->shapeType, sizeof(shape->shapeType), "Rectangle");
            displayArea(*shape);
            break;
        }
        case 3: {
            double base, height;
            printf("Enter the base and height of the triangle: ");
            scanf("%lf %lf", &base, &height);
            shape->area = calculateTriangleArea(base, height);
            snprintf(shape->shapeType, sizeof(shape->shapeType), "Triangle");
            displayArea(*shape);
            break;
        }
        default:
            printf("Invalid choice! Please run the program again and select a valid option.\n");
            break;
    }

    // Free the dynamically allocated memory
    free(shape);
    return 0;
}