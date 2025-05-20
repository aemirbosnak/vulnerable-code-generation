//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float area;
} Shape;

void calculateCircleArea(Shape *shape, float radius) {
    shape->area = 3.14159 * radius * radius;
    strcpy(shape->name, "Circle");
}

void calculateSquareArea(Shape *shape, float side) {
    shape->area = side * side;
    strcpy(shape->name, "Square");
}

void calculateTriangleArea(Shape *shape, float base, float height) {
    shape->area = 0.5 * base * height;
    strcpy(shape->name, "Triangle");
}

void displayShape(Shape shape) {
    printf("Shape: %s, Area: %.2f\n", shape.name, shape.area);
}

int main() {
    Shape shapes[MAX_SHAPES];
    int shapeCount = 0;
    int choice;

    printf("Welcome to the Shape Area Calculator!\n");

    while (1) {
        printf("\nChoose a shape to calculate area:\n");
        printf("1. Circle\n");
        printf("2. Square\n");
        printf("3. Triangle\n");
        printf("4. Display all shapes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        if (choice == 5) {
            break;  // Exit the loop
        }

        float dimension1, dimension2;
        
        switch (choice) {
            case 1:  // Circle
                printf("Enter the radius of the circle: ");
                scanf("%f", &dimension1);
                calculateCircleArea(&shapes[shapeCount], dimension1);
                shapeCount++;
                break;

            case 2:  // Square
                printf("Enter the side length of the square: ");
                scanf("%f", &dimension1);
                calculateSquareArea(&shapes[shapeCount], dimension1);
                shapeCount++;
                break;

            case 3:  // Triangle
                printf("Enter the base of the triangle: ");
                scanf("%f", &dimension1);
                printf("Enter the height of the triangle: ");
                scanf("%f", &dimension2);
                calculateTriangleArea(&shapes[shapeCount], dimension1, dimension2);
                shapeCount++;
                break;

            case 4:  // Display all shapes
                printf("\nAll shapes calculated:\n");
                for (int i = 0; i < shapeCount; i++) {
                    displayShape(shapes[i]);
                }
                break;
        }

        if (shapeCount >= MAX_SHAPES) {
            printf("Maximum shape limit reached. Displaying all shapes.\n");
            for (int i = 0; i < shapeCount; i++) {
                displayShape(shapes[i]);
            }
            break;
        }
    }

    printf("Thank you for using the Shape Area Calculator!\n");
    return 0;
}