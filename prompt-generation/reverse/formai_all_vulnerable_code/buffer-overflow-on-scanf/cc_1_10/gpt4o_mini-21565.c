//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 10

typedef struct Shape {
    char* name;
    int vertices;
} Shape;

typedef struct Circle {
    Shape shape;
    float radius;
} Circle;

typedef struct Rectangle {
    Shape shape;
    float width;
    float height;
} Rectangle;

typedef struct Triangle {
    Shape shape;
    float base;
    float height;
} Triangle;

typedef union {
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
} ShapeUnion;

typedef struct ShapeContainer {
    ShapeUnion shape;
    int type; // 0 for Circle, 1 for Rectangle, 2 for Triangle
} ShapeContainer;

void drawCircle(float radius) {
    printf("Drawing a Circle with radius: %.2f\n", radius);
}

void drawRectangle(float width, float height) {
    printf("Drawing a Rectangle with width: %.2f and height: %.2f\n", width, height);
}

void drawTriangle(float base, float height) {
    printf("Drawing a Triangle with base: %.2f and height: %.2f\n", base, height);
}

void visualizeShape(ShapeContainer* container) {
    switch (container->type) {
    case 0:
        drawCircle(container->shape.circle.radius);
        break;
    case 1:
        drawRectangle(container->shape.rectangle.width, container->shape.rectangle.height);
        break;
    case 2:
        drawTriangle(container->shape.triangle.base, container->shape.triangle.height);
        break;
    default:
        printf("Invalid shape type.\n");
        break;
    }
}

void shapeShifter(ShapeContainer* container) {
    printf("Choose the shape to visualize:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        container->type = 0;
        printf("Enter radius for Circle: ");
        scanf("%f", &container->shape.circle.radius);
        strcpy(container->shape.circle.shape.name, "Circle");
        container->shape.circle.shape.vertices = 0; // Circle has no vertices
        break;
    case 2:
        container->type = 1;
        printf("Enter width for Rectangle: ");
        scanf("%f", &container->shape.rectangle.width);
        printf("Enter height for Rectangle: ");
        scanf("%f", &container->shape.rectangle.height);
        strcpy(container->shape.rectangle.shape.name, "Rectangle");
        container->shape.rectangle.shape.vertices = 4; // Rectangle has 4 vertices
        break;
    case 3:
        container->type = 2;
        printf("Enter base for Triangle: ");
        scanf("%f", &container->shape.triangle.base);
        printf("Enter height for Triangle: ");
        scanf("%f", &container->shape.triangle.height);
        strcpy(container->shape.triangle.shape.name, "Triangle");
        container->shape.triangle.shape.vertices = 3; // Triangle has 3 vertices
        break;
    default:
        printf("Invalid choice. Defaulting to Circle.\n");
        container->type = 0;
        container->shape.circle.radius = 1.0f;
        strcpy(container->shape.circle.shape.name, "Circle");
        container->shape.circle.shape.vertices = 0;
        break;
    }

    visualizeShape(container);
}

int main() {
    ShapeContainer container;
    container.shape.circle.shape.name = (char*)malloc(20 * sizeof(char));
    
    while (1) {
        shapeShifter(&container);
        printf("\nWould you like to visualize another shape? (y/n): ");
        char continueChoice;
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y') {
            break;
        }
        printf("\n");
        sleep(1); // Sleep for visual effect
    }

    free(container.shape.circle.shape.name);
    printf("Exiting Shape Shifter Program. Goodbye!\n");
    return 0;
}