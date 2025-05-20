//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Base shape structure
typedef struct Shape {
    void (*transform)(struct Shape *self);
    double (*area)(struct Shape *self);
    double (*perimeter)(struct Shape *self);
    char name[20];
} Shape;

// Circle structure
typedef struct {
    Shape base;
    double radius;
} Circle;

// Square structure
typedef struct {
    Shape base;
    double side;
} Square;

// Triangle structure
typedef struct {
    Shape base;
    double base_length;
    double height;
} Triangle;

// Function prototypes
double circle_area(Shape *self);
double circle_perimeter(Shape *self);
void circle_transform(Shape *self);

double square_area(Shape *self);
double square_perimeter(Shape *self);
void square_transform(Shape *self);

double triangle_area(Shape *self);
double triangle_perimeter(Shape *self);
void triangle_transform(Shape *self);

// Circle methods
double circle_area(Shape *self) {
    Circle *circle = (Circle *)self;
    return M_PI * circle->radius * circle->radius;
}

double circle_perimeter(Shape *self) {
    Circle *circle = (Circle *)self;
    return 2 * M_PI * circle->radius;
}

void circle_transform(Shape *self) {
    printf("Transforming Circle into a Square...\n");
    Circle *circle = (Circle *)self;
    Square *square = (Square *)malloc(sizeof(Square));
    strcpy(square->base.name, "Square");
    square->side = circle->radius * sqrt(2);  // Assuming square inscribed in circle
    square->base.area = square_area;
    square->base.perimeter = square_perimeter;
    square->base.transform = square_transform;

    printf("New Shape: %s\nArea: %.2f\nPerimeter: %.2f\n", 
           square->base.name, 
           square->base.area((Shape *)square), 
           square->base.perimeter((Shape *)square));

    free(square);
}

// Square methods
double square_area(Shape *self) {
    Square *square = (Square *)self;
    return square->side * square->side;
}

double square_perimeter(Shape *self) {
    Square *square = (Square *)self;
    return 4 * square->side;
}

void square_transform(Shape *self) {
    printf("Transforming Square into a Triangle...\n");
    Square *square = (Square *)self;
    Triangle *triangle = (Triangle *)malloc(sizeof(Triangle));
    strcpy(triangle->base.name, "Triangle");
    triangle->base_length = square->side;
    triangle->height = square->side * sqrt(3) / 2;  // Height of an equilateral triangle

    triangle->base.area = triangle_area;
    triangle->base.perimeter = triangle_perimeter;
    triangle->base.transform = triangle_transform;

    printf("New Shape: %s\nArea: %.2f\nPerimeter: %.2f\n", 
           triangle->base.name, 
           triangle->base.area((Shape *)triangle), 
           triangle->base.perimeter((Shape *)triangle));

    free(triangle);
}

// Triangle methods
double triangle_area(Shape *self) {
    Triangle *triangle = (Triangle *)self;  
    return 0.5 * triangle->base_length * triangle->height;
}

double triangle_perimeter(Shape *self) {
    Triangle *triangle = (Triangle *)self;
    // Assuming an equilateral triangle for simplicity
    return 3 * triangle->base_length;
}

void triangle_transform(Shape *self) {
    printf("Transforming Triangle into a Circle...\n");
    Triangle *triangle = (Triangle *)self;
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    strcpy(circle->base.name, "Circle");
    circle->radius = triangle->base_length / sqrt(3);  // Radius of circle inscribed in triangle
    circle->base.area = circle_area;
    circle->base.perimeter = circle_perimeter;
    circle->base.transform = circle_transform;

    printf("New Shape: %s\nArea: %.2f\nPerimeter: %.2f\n", 
           circle->base.name, 
           circle->base.area((Shape *)circle), 
           circle->base.perimeter((Shape *)circle));

    free(circle);
}

// User interaction function
void select_shape() {
    int choice;
    do {
        printf("Select a shape to transform:\n");
        printf("1. Circle\n2. Square\n3. Triangle\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        Shape *shape = NULL;
        switch (choice) {
            case 1: {
                Circle *circle = (Circle *)malloc(sizeof(Circle));
                printf("Enter radius: ");
                scanf("%lf", &circle->radius);
                strcpy(circle->base.name, "Circle");
                circle->base.area = circle_area;
                circle->base.perimeter = circle_perimeter;
                circle->base.transform = circle_transform;
                shape = (Shape *)circle;
                break;
            }
            case 2: {
                Square *square = (Square *)malloc(sizeof(Square));
                printf("Enter side length: ");
                scanf("%lf", &square->side);
                strcpy(square->base.name, "Square");
                square->base.area = square_area;
                square->base.perimeter = square_perimeter;
                square->base.transform = square_transform;
                shape = (Shape *)square;
                break;
            }
            case 3: {
                Triangle *triangle = (Triangle *)malloc(sizeof(Triangle));
                printf("Enter base length: ");
                scanf("%lf", &triangle->base_length);
                printf("Enter height: ");
                scanf("%lf", &triangle->height);
                strcpy(triangle->base.name, "Triangle");
                triangle->base.area = triangle_area;
                triangle->base.perimeter = triangle_perimeter;
                triangle->base.transform = triangle_transform;
                shape = (Shape *)triangle;
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        if (shape && choice != 4) {
            printf("Selected Shape: %s\nArea: %.2f\nPerimeter: %.2f\n",
                   shape->name,
                   shape->area(shape),
                   shape->perimeter(shape));
            shape->transform(shape);
            free(shape);
        }
    } while (choice != 4);
}

// Main entry point
int main() {
    select_shape();
    return 0;
}