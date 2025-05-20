//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SHAPES 10

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_TRIANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    union {
        struct {
            double radius;
        } circle;
        struct {
            double side;
        } square;
        struct {
            double base;
            double height;
        } triangle;
    };
} Shape;

void calculate_area(Shape *shape) {
    switch (shape->type) {
        case SHAPE_CIRCLE:
            printf("Area of Circle: %.2f\n", M_PI * shape->circle.radius * shape->circle.radius);
            break;
        case SHAPE_SQUARE:
            printf("Area of Square: %.2f\n", shape->square.side * shape->square.side);
            break;
        case SHAPE_TRIANGLE:
            printf("Area of Triangle: %.2f\n", 0.5 * shape->triangle.base * shape->triangle.height);
            break;
        default:
            printf("Unknown shape!\n");
    }
}

void print_shape_info(Shape *shape) {
    switch (shape->type) {
        case SHAPE_CIRCLE:
            printf("Shape: Circle with Radius: %.2f\n", shape->circle.radius);
            break;
        case SHAPE_SQUARE:
            printf("Shape: Square with Side: %.2f\n", shape->square.side);
            break;
        case SHAPE_TRIANGLE:
            printf("Shape: Triangle with Base: %.2f and Height: %.2f\n", shape->triangle.base, shape->triangle.height);
            break;
    }
}

Shape* create_shape(ShapeType type) {
    Shape *new_shape = (Shape *)malloc(sizeof(Shape));
    if (new_shape == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_shape->type = type;

    switch (type) {
        case SHAPE_CIRCLE:
            printf("Enter radius of circle: ");
            scanf("%lf", &new_shape->circle.radius);
            break;
        case SHAPE_SQUARE:
            printf("Enter side of square: ");
            scanf("%lf", &new_shape->square.side);
            break;
        case SHAPE_TRIANGLE:
            printf("Enter base and height of triangle: ");
            scanf("%lf %lf", &new_shape->triangle.base, &new_shape->triangle.height);
            break;
    }
    return new_shape;
}

void shift_shape(Shape **current_shape, ShapeType new_type) {
    Shape *temp_shape = create_shape(new_type);
    *current_shape = realloc(*current_shape, sizeof(Shape));
    if (*current_shape == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    **current_shape = *temp_shape;
    free(temp_shape);
}

void free_shape(Shape *shape) {
    free(shape);
}

int main() {
    Shape *shapes[MAX_SHAPES];
    int shape_count = 0;
    int choice;

    while (1) {
        printf("\nShape-Shifting Menu:\n");
        printf("1. Create Circle\n");
        printf("2. Create Square\n");
        printf("3. Create Triangle\n");
        printf("4. Shift Shape\n");
        printf("5. Calculate Area\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (shape_count < MAX_SHAPES) {
                    shapes[shape_count++] = create_shape(SHAPE_CIRCLE);
                } else {
                    printf("Maximum shape limit reached.\n");
                }
                break;
            case 2:
                if (shape_count < MAX_SHAPES) {
                    shapes[shape_count++] = create_shape(SHAPE_SQUARE);
                } else {
                    printf("Maximum shape limit reached.\n");
                }
                break;
            case 3:
                if (shape_count < MAX_SHAPES) {
                    shapes[shape_count++] = create_shape(SHAPE_TRIANGLE);
                } else {
                    printf("Maximum shape limit reached.\n");
                }
                break;
            case 4:
                if (shape_count > 0) {
                    int shape_index;
                    printf("Enter the index (0 to %d) of the shape to shift: ", shape_count - 1);
                    scanf("%d", &shape_index);
                    if (shape_index >= 0 && shape_index < shape_count) {
                        int new_shape_type;
                        printf("Select new shape type (0 - Circle, 1 - Square, 2 - Triangle): ");
                        scanf("%d", &new_shape_type);
                        if (new_shape_type >= 0 && new_shape_type <= 2) {
                            shift_shape(&shapes[shape_index], (ShapeType)new_shape_type);
                            printf("Shape shifted successfully!\n");
                        } else {
                            printf("Invalid shape type!\n");
                        }
                    } else {
                        printf("Invalid shape index!\n");
                    }
                } else {
                    printf("No shapes available to shift.\n");
                }
                break;
            case 5:
                if (shape_count > 0) {
                    int shape_index;
                    printf("Enter the index (0 to %d) of the shape to calculate area: ", shape_count - 1);
                    scanf("%d", &shape_index);
                    if (shape_index >= 0 && shape_index < shape_count) {
                        print_shape_info(shapes[shape_index]);
                        calculate_area(shapes[shape_index]);
                    } else {
                        printf("Invalid shape index!\n");
                    }
                } else {
                    printf("No shapes available to calculate area.\n");
                }
                break;
            case 6:
                for (int i = 0; i < shape_count; ++i) {
                    free_shape(shapes[i]);
                }
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option selected!\n");
        }
    }

    return 0;
}