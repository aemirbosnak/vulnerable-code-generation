//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_TRIANGLE,
    SHAPE_INVALID
} ShapeType;

typedef struct {
    ShapeType type;
    char *name;
    double (*area)(double);
    double (*perimeter)(double);
    void (*draw)(double);
} Shape;

double circle_area(double radius) {
    return PI * radius * radius;
}

double circle_perimeter(double radius) {
    return 2 * PI * radius;
}

void draw_circle(double radius) {
    int r = (int)radius;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if (i * i + j * j <= r * r) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

double square_area(double side) {
    return side * side;
}

double square_perimeter(double side) {
    return 4 * side;
}

void draw_square(double side) {
    int s = (int)side;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            printf("*");
        }
        printf("\n");
    }
}

double triangle_area(double base) {
    return (sqrt(3) / 4) * base * base;
}

double triangle_perimeter(double base) {
    double side = base; // For an equilateral triangle
    return 3 * side;
}

void draw_triangle(double base) {
    int h = (int)(sqrt(3) / 2 * base);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < base; j++) {
            if (j >= h - i && j <= h + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void initialize_shapes(Shape *shapes) {
    shapes[0] = (Shape){SHAPE_CIRCLE, "Circle", circle_area, circle_perimeter, draw_circle};
    shapes[1] = (Shape){SHAPE_SQUARE, "Square", square_area, square_perimeter, draw_square};
    shapes[2] = (Shape){SHAPE_TRIANGLE, "Triangle", triangle_area, triangle_perimeter, draw_triangle};
}

void display_menu() {
    printf("Choose a shape to visualize:\n");
    printf("1. Circle\n");
    printf("2. Square\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
}

int main() {
    Shape shapes[3];
    initialize_shapes(shapes);
    
    int choice;
    double dimension;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter the dimension (radius/side/base): ");
        scanf("%lf", &dimension);

        if (dimension <= 0) {
            printf("Dimension must be positive.\n");
            continue;
        }

        Shape selected_shape = shapes[choice - 1];

        printf("Area of %s: %.2f\n", selected_shape.name, selected_shape.area(dimension));
        printf("Perimeter of %s: %.2f\n", selected_shape.name, selected_shape.perimeter(dimension));
        printf("Drawn %s:\n", selected_shape.name);
        selected_shape.draw(dimension);
    }

    printf("Thank you for using the shape visualizer!\n");
    return 0;
}