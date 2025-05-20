//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SHAPES 100

typedef enum {
    CIRCLE,
    RECTANGLE
} ShapeType;

typedef struct {
    ShapeType type;
    union {
        struct {
            float radius;
        } circle;
        struct {
            float width;
            float height;
        } rectangle;
    } data;
    float area;
} Shape;

float compute_area(Shape shape) {
    if (shape.type == CIRCLE) {
        return M_PI * shape.data.circle.radius * shape.data.circle.radius;
    } else {
        return shape.data.rectangle.width * shape.data.rectangle.height;
    }
}

int compare_shapes(const void *a, const void *b) {
    Shape *shapeA = (Shape *)a;
    Shape *shapeB = (Shape *)b;
    if (shapeA->area < shapeB->area) return -1;
    else if (shapeA->area > shapeB->area) return 1;
    else return 0;
}

void input_shape(Shape *shape) {
    printf("Enter shape type (0 for Circle, 1 for Rectangle): ");
    scanf("%d", &(shape->type));

    if (shape->type == CIRCLE) {
        printf("Enter radius of the circle: ");
        scanf("%f", &(shape->data.circle.radius));
    } else if (shape->type == RECTANGLE) {
        printf("Enter width and height of the rectangle: ");
        scanf("%f %f", &(shape->data.rectangle.width), &(shape->data.rectangle.height));
    }

    // Calculate area after inputting shape details
    shape->area = compute_area(*shape);
}

void print_shapes(Shape *shapes, int count) {
    printf("\nSorted shapes based on area:\n");
    for (int i = 0; i < count; i++) {
        if (shapes[i].type == CIRCLE) {
            printf("Circle: radius = %.2f, area = %.2f\n", shapes[i].data.circle.radius, shapes[i].area);
        } else if (shapes[i].type == RECTANGLE) {
            printf("Rectangle: width = %.2f, height = %.2f, area = %.2f\n", shapes[i].data.rectangle.width,
                   shapes[i].data.rectangle.height, shapes[i].area);
        }
    }
}

int main() {
    Shape shapes[MAX_SHAPES];
    int count;

    printf("Enter the number of shapes (max %d): ", MAX_SHAPES);
    scanf("%d", &count);
    if (count > MAX_SHAPES) {
        printf("Exceeds maximum shape count! Limiting to %d.\n", MAX_SHAPES);
        count = MAX_SHAPES;
    }

    for (int i = 0; i < count; i++) {
        input_shape(&shapes[i]);
    }

    // Sort shapes based on area
    qsort(shapes, count, sizeof(Shape), compare_shapes);

    // Display sorted shapes
    print_shapes(shapes, count);

    return 0;
}