//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SHAPES 3

typedef struct {
    char type[20];
    float dimension1; // Used for radius (circle) or base (triangle/rectangle)
    float dimension2; // Used for height (triangle) or width (rectangle)
} Shape;

void calculateArea(Shape* shape) {
    if (strcmp(shape->type, "circle") == 0) {
        float area = M_PI * shape->dimension1 * shape->dimension1;
        printf("The area of the circle with radius %.2f is: %.2f\n", shape->dimension1, area);
    } else if (strcmp(shape->type, "rectangle") == 0) {
        float area = shape->dimension1 * shape->dimension2;
        printf("The area of the rectangle with width %.2f and height %.2f is: %.2f\n", shape->dimension1, shape->dimension2, area);
    } else if (strcmp(shape->type, "triangle") == 0) {
        float area = 0.5 * shape->dimension1 * shape->dimension2;
        printf("The area of the triangle with base %.2f and height %.2f is: %.2f\n", shape->dimension1, shape->dimension2, area);
    } else {
        printf("Invalid shape type: %s. Cannot calculate area.\n", shape->type);
    }
}

void inputShape(Shape* shape) {
    printf("Enter shape type (circle/rectangle/triangle): ");
    scanf("%s", shape->type);
    
    if (strcmp(shape->type, "circle") == 0) {
        printf("Enter the radius: ");
        scanf("%f", &shape->dimension1);
        shape->dimension2 = 0; // Not used for circle
    } else if (strcmp(shape->type, "rectangle") == 0) {
        printf("Enter the width: ");
        scanf("%f", &shape->dimension1);
        printf("Enter the height: ");
        scanf("%f", &shape->dimension2);
    } else if (strcmp(shape->type, "triangle") == 0) {
        printf("Enter the base: ");
        scanf("%f", &shape->dimension1);
        printf("Enter the height: ");
        scanf("%f", &shape->dimension2);
    } else {
        printf("Invalid shape type. Defaulting to circle with radius 0.\n");
        strcpy(shape->type, "circle");
        shape->dimension1 = 0.0;
        shape->dimension2 = 0.0;
    }
}

int main() {
    Shape* shapes = malloc(MAX_SHAPES * sizeof(Shape));
    if (shapes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    
    for (int i = 0; i < MAX_SHAPES; i++) {
        printf("\n--- Shape %d ---\n", i + 1);
        inputShape(&shapes[i]);
        calculateArea(&shapes[i]);
    }

    free(shapes);
    return 0;
}