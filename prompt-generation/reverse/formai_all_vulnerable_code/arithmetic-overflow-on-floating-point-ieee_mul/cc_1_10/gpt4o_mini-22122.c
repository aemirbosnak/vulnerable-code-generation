//GPT-4o-mini DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SHAPES 5

typedef enum {
    SHAPE_SQUARE,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    float size; // For square side, circle radius, and triangle base/height
    float height; // Only for triangle
} Shape;

void drawSquare(float size) {
    printf("\nDrawing a square of size %.2f:\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawCircle(float radius) {
    printf("\nDrawing a circle of radius %.2f:\n", radius);
    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void drawTriangle(float base, float height) {
    printf("\nDrawing a triangle with base %.2f and height %.2f:\n", base, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (int)(base / 2.0) - i; j++)
            printf("  ");
        for (int j = 0; j < (i * 2) + 1; j++)
            printf("*");
        printf("\n");
    }
}

Shape* createRandomShape() {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    shape->type = rand() % 3;
    shape->size = (rand() % 10) + 1; // Size between 1 and 10
    if (shape->type == SHAPE_TRIANGLE) {
        shape->height = (rand() % 10) + 1; // Height for triangle
    }
    return shape;
}

void displayShape(Shape* shape) {
    switch(shape->type) {
        case SHAPE_SQUARE:
            drawSquare(shape->size);
            break;
        case SHAPE_CIRCLE:
            drawCircle(shape->size);
            break;
        case SHAPE_TRIANGLE:
            drawTriangle(shape->size, shape->height);
            break;
    }
}

int main() {
    srand(time(0));
    Shape* shapes[MAX_SHAPES];

    printf("Welcome to the Shape Shifting Game!\n");
    printf("Let's create some shapes!\n");

    for (int i = 0; i < MAX_SHAPES; i++) {
        shapes[i] = createRandomShape();
        displayShape(shapes[i]);
        free(shapes[i]);
    }

    printf("Thanks for playing the Shape Shifting Game!\n");
    return 0;
}