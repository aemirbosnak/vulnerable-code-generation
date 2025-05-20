//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 100
#define MAX_NAME_LENGTH 20
#define PI 3.14159265

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_RECTANGLE,
    SHAPE_TRIANGLE,
    SHAPE_ERROR
} ShapeType;

typedef struct {
    ShapeType type;
    char name[MAX_NAME_LENGTH];
    float area;
} Shape;

void calculateCircleArea(Shape *shape, float radius) {
    if (radius < 0) {
        fprintf(stderr, "Error: Radius cannot be negative for circle '%s'\n", shape->name);
        shape->type = SHAPE_ERROR;
        return;
    }
    shape->area = PI * radius * radius;
}

void calculateSquareArea(Shape *shape, float side) {
    if (side < 0) {
        fprintf(stderr, "Error: Side length cannot be negative for square '%s'\n", shape->name);
        shape->type = SHAPE_ERROR;
        return;
    }
    shape->area = side * side;
}

void calculateRectangleArea(Shape *shape, float length, float width) {
    if (length < 0 || width < 0) {
        fprintf(stderr, "Error: Length and width cannot be negative for rectangle '%s'\n", shape->name);
        shape->type = SHAPE_ERROR;
        return;
    }
    shape->area = length * width;
}

void calculateTriangleArea(Shape *shape, float base, float height) {
    if (base < 0 || height < 0) {
        fprintf(stderr, "Error: Base and height cannot be negative for triangle '%s'\n", shape->name);
        shape->type = SHAPE_ERROR;
        return;
    }
    shape->area = 0.5 * base * height;
}

void printShapeDetails(Shape *shape) {
    if (shape->type == SHAPE_ERROR) {
        fprintf(stdout, "Shape '%s' could not be calculated due to previous errors.\n", shape->name);
    } else {
        fprintf(stdout, "Shape '%s' of type ", shape->name);
        switch (shape->type) {
            case SHAPE_CIRCLE:
                fprintf(stdout, "Circle with area: %.2f\n", shape->area);
                break;
            case SHAPE_SQUARE:
                fprintf(stdout, "Square with area: %.2f\n", shape->area);
                break;
            case SHAPE_RECTANGLE:
                fprintf(stdout, "Rectangle with area: %.2f\n", shape->area);
                break;
            case SHAPE_TRIANGLE:
                fprintf(stdout, "Triangle with area: %.2f\n", shape->area);
                break;
            default:
                fprintf(stdout, "Unknown shape type!\n");
                break;
        }
    }
}

int main() {
    Shape shapes[MAX_SHAPES];
    int shapeCount = 0;

    char shapeName[MAX_NAME_LENGTH];
    float input1, input2;

    // Circle Example
    strcpy(shapeName, "Circle1");
    shapes[shapeCount].type = SHAPE_CIRCLE;
    strcpy(shapes[shapeCount].name, shapeName);
    printf("Enter radius for %s: ", shapes[shapeCount].name);
    scanf("%f", &input1);
    calculateCircleArea(&shapes[shapeCount], input1);
    printShapeDetails(&shapes[shapeCount]);
    shapeCount++;

    // Square Example
    strcpy(shapeName, "Square1");
    shapes[shapeCount].type = SHAPE_SQUARE;
    strcpy(shapes[shapeCount].name, shapeName);
    printf("Enter side length for %s: ", shapes[shapeCount].name);
    scanf("%f", &input1);
    calculateSquareArea(&shapes[shapeCount], input1);
    printShapeDetails(&shapes[shapeCount]);
    shapeCount++;

    // Rectangle Example
    strcpy(shapeName, "Rectangle1");
    shapes[shapeCount].type = SHAPE_RECTANGLE;
    strcpy(shapes[shapeCount].name, shapeName);
    printf("Enter length and width for %s (separated by space): ", shapes[shapeCount].name);
    scanf("%f %f", &input1, &input2);
    calculateRectangleArea(&shapes[shapeCount], input1, input2);
    printShapeDetails(&shapes[shapeCount]);
    shapeCount++;

    // Triangle Example
    strcpy(shapeName, "Triangle1");
    shapes[shapeCount].type = SHAPE_TRIANGLE;
    strcpy(shapes[shapeCount].name, shapeName);
    printf("Enter base and height for %s (separated by space): ", shapes[shapeCount].name);
    scanf("%f %f", &input1, &input2);
    calculateTriangleArea(&shapes[shapeCount], input1, input2);
    printShapeDetails(&shapes[shapeCount]);
    shapeCount++;

    return 0;
}