//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SHAPES 100
#define MAX_NAME_LENGTH 50

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_TRIANGLE,
    SHAPE_UNKNOWN
} ShapeType;

typedef struct {
    ShapeType type;
    char name[MAX_NAME_LENGTH];
    float area;
} Shape;

float calculate_circle_area(float radius) {
    return 3.14159 * radius * radius;
}

float calculate_square_area(float side) {
    return side * side;
}

float calculate_triangle_area(float base, float height) {
    return 0.5 * base * height;
}

void print_shape(Shape* shape) {
    if (shape->type == SHAPE_CIRCLE) {
        printf("Shape: Circle, Name: %s, Area: %.2f\n", shape->name, shape->area);
    } else if (shape->type == SHAPE_SQUARE) {
        printf("Shape: Square, Name: %s, Area: %.2f\n", shape->name, shape->area);
    } else if (shape->type == SHAPE_TRIANGLE) {
        printf("Shape: Triangle, Name: %s, Area: %.2f\n", shape->name, shape->area);
    } else {
        printf("Shape: Unknown\n");
    }
}

int main() {
    Shape **shapes = malloc(MAX_SHAPES * sizeof(Shape*));
    int count = 0;
    int action;

    if (shapes == NULL) {
        fprintf(stderr, "Failed to allocate memory for shapes.\n");
        return 1;
    }

    while (1) {
        printf("\nShape Management System\n");
        printf("1. Add Circle\n");
        printf("2. Add Square\n");
        printf("3. Add Triangle\n");
        printf("4. Show Shapes\n");
        printf("5. Exit\n");
        printf("Choose an action (1-5): ");
        scanf("%d", &action);

        if (action == 5) {
            break;
        }

        if (count >= MAX_SHAPES) {
            printf("Maximum number of shapes reached.\n");
            continue;
        }

        shapes[count] = malloc(sizeof(Shape));
        if (shapes[count] == NULL) {
            fprintf(stderr, "Failed to allocate memory for shape.\n");
            continue;
        }

        switch (action) {
            case 1: // Add Circle
                shapes[count]->type = SHAPE_CIRCLE;
                printf("Enter name for Circle: ");
                scanf("%s", shapes[count]->name);
                float radius;
                printf("Enter radius: ");
                scanf("%f", &radius);
                shapes[count]->area = calculate_circle_area(radius);
                count++;
                break;

            case 2: // Add Square
                shapes[count]->type = SHAPE_SQUARE;
                printf("Enter name for Square: ");
                scanf("%s", shapes[count]->name);
                float side;
                printf("Enter side length: ");
                scanf("%f", &side);
                shapes[count]->area = calculate_square_area(side);
                count++;
                break;

            case 3: // Add Triangle
                shapes[count]->type = SHAPE_TRIANGLE;
                printf("Enter name for Triangle: ");
                scanf("%s", shapes[count]->name);
                float base, height;
                printf("Enter base length: ");
                scanf("%f", &base);
                printf("Enter height: ");
                scanf("%f", &height);
                shapes[count]->area = calculate_triangle_area(base, height);
                count++;
                break;

            case 4: // Show Shapes
                printf("\nShapes List:\n");
                for (int i = 0; i < count; i++) {
                    print_shape(shapes[i]);
                }
                break;

            default:
                printf("Invalid action! Please try again.\n");
                free(shapes[count]); // Free allocated memory on error
                shapes[count] = NULL;
                break;
        }
    }

    // Free allocated shapes
    for (int i = 0; i < count; i++) {
        free(shapes[i]);
    }
    free(shapes);

    printf("Goodbye!\n");
    return 0;
}