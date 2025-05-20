//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SHAPES 5
#define MAX_LEN 10

// Enum for different shape types
typedef enum {
    TRIANGLE,
    SQUARE,
    CIRCLE,
    RECTANGLE,
    HEXAGON
} ShapeType;

// Structure to hold shape properties
typedef struct {
    ShapeType type;
    double area;
    double perimeter;
    double dimensions[MAX_LEN]; // For different shapes, store respective dimensions
} Shape;

// Function prototypes
void calculateAreaAndPerimeter(Shape *shape);
void inputShapeDimensions(Shape *shape);
void displayShapeInfo(const Shape *shape);
void printShapeShape(ShapeType type);

// Main function
int main() {
    srand(time(NULL)); // Seed for random generation

    Shape shapes[MAX_SHAPES];
    int i;

    // Generate shapes and compute properties
    for (i = 0; i < MAX_SHAPES; i++) {
        shapes[i].type = rand() % 5; // Randomly assigning shapes from enum
        inputShapeDimensions(&shapes[i]);
        calculateAreaAndPerimeter(&shapes[i]);
    }

    // Display results 
    for (i = 0; i < MAX_SHAPES; i++) {
        displayShapeInfo(&shapes[i]);
    }

    return 0;
}

// Function to compute area and perimeter based on shape type
void calculateAreaAndPerimeter(Shape *shape) {
    switch (shape->type) {
        case TRIANGLE:
            shape->area = 0.5 * shape->dimensions[0] * shape->dimensions[1]; // 1st and 2nd elements as base and height
            shape->perimeter = shape->dimensions[0] + shape->dimensions[1] + shape->dimensions[2]; // sum of all three sides
            break;
        case SQUARE:
            shape->area = shape->dimensions[0] * shape->dimensions[0]; // 1st element as length of side
            shape->perimeter = 4 * shape->dimensions[0]; // 4 sides
            break;
        case CIRCLE:
            shape->area = 3.14159 * shape->dimensions[0] * shape->dimensions[0]; // 1st element as radius
            shape->perimeter = 2 * 3.14159 * shape->dimensions[0]; // circumference
            break;
        case RECTANGLE:
            shape->area = shape->dimensions[0] * shape->dimensions[1]; // 1st and 2nd as length and width
            shape->perimeter = 2 * (shape->dimensions[0] + shape->dimensions[1]); 
            break;
        case HEXAGON:
            shape->area =  ((3 * sqrt(3)) / 2) * shape->dimensions[0] * shape->dimensions[0]; // 1st element as side length
            shape->perimeter = 6 * shape->dimensions[0]; // 6 sides
            break;
        default:
            fprintf(stderr, "Unknown shape type.\n");
            exit(EXIT_FAILURE);
    }
}

// Function to input shape dimensions
void inputShapeDimensions(Shape *shape) {
    switch (shape->type) {
        case TRIANGLE:
            printf("Enter base and height of the triangle: ");
            scanf("%lf %lf", &shape->dimensions[0], &shape->dimensions[1]);
            printf("Enter two other sides of the triangle: ");
            scanf("%lf", &shape->dimensions[2]);
            break;
        case SQUARE:
            printf("Enter the side length of the square: ");
            scanf("%lf", &shape->dimensions[0]);
            break;
        case CIRCLE:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &shape->dimensions[0]);
            break;
        case RECTANGLE:
            printf("Enter length and width of the rectangle: ");
            scanf("%lf %lf", &shape->dimensions[0], &shape->dimensions[1]);
            break;
        case HEXAGON:
            printf("Enter the side length of the hexagon: ");
            scanf("%lf", &shape->dimensions[0]);
            break;
        default:
            fprintf(stderr, "Unknown shape type.\n");
            exit(EXIT_FAILURE);
    }
}

// Function to display shape info
void displayShapeInfo(const Shape *shape) {
    printf("\nShape Information:\n");
    printShapeShape(shape->type);
    printf("Area: %.2lf\n", shape->area);
    printf("Perimeter: %.2lf\n", shape->perimeter);
}

// Function to print shape type based on enum
void printShapeShape(ShapeType type) {
    switch (type) {
        case TRIANGLE: printf("Triangle\n"); break;
        case SQUARE: printf("Square\n"); break;
        case CIRCLE: printf("Circle\n"); break;
        case RECTANGLE: printf("Rectangle\n"); break;
        case HEXAGON: printf("Hexagon\n"); break;
        default: printf("Unknown Shape\n"); 
    }
}