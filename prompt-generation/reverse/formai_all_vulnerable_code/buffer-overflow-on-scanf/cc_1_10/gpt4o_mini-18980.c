//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a Circle
typedef struct {
    double radius;
} Circle;

// Structure to represent a Rectangle
typedef struct {
    double length;
    double width;
} Rectangle;

// Structure to represent a Triangle
typedef struct {
    double base;
    double height;
} Triangle;

// Function to calculate area of a Circle
double calculate_circle_area(Circle *circle) {
    return M_PI * circle->radius * circle->radius;
}

// Function to calculate perimeter of a Circle
double calculate_circle_perimeter(Circle *circle) {
    return 2 * M_PI * circle->radius;
}

// Function to calculate area of a Rectangle
double calculate_rectangle_area(Rectangle *rectangle) {
    return rectangle->length * rectangle->width;
}

// Function to calculate perimeter of a Rectangle
double calculate_rectangle_perimeter(Rectangle *rectangle) {
    return 2 * (rectangle->length + rectangle->width);
}

// Function to calculate area of a Triangle
double calculate_triangle_area(Triangle *triangle) {
    return 0.5 * triangle->base * triangle->height;
}

// Function to calculate perimeter of a Triangle (assuming an equilateral triangle)
double calculate_triangle_perimeter(Triangle *triangle) {
    return 3 * triangle->base; // Simple perimeter for an equilateral triangle
}

// Function to display menu and get user choice
int display_menu() {
    int choice;

    printf("\n=== Geometric Shape Calculator ===\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Function to handle circle calculations
void handle_circle() {
    Circle *circle = malloc(sizeof(Circle));
    if (circle == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the radius of the circle: ");
    scanf("%lf", &circle->radius);

    printf("Circle Area: %.2lf\n", calculate_circle_area(circle));
    printf("Circle Perimeter: %.2lf\n", calculate_circle_perimeter(circle));

    free(circle);
}

// Function to handle rectangle calculations
void handle_rectangle() {
    Rectangle *rectangle = malloc(sizeof(Rectangle));
    if (rectangle == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the length and width of the rectangle: ");
    scanf("%lf %lf", &rectangle->length, &rectangle->width);

    printf("Rectangle Area: %.2lf\n", calculate_rectangle_area(rectangle));
    printf("Rectangle Perimeter: %.2lf\n", calculate_rectangle_perimeter(rectangle));

    free(rectangle);
}

// Function to handle triangle calculations
void handle_triangle() {
    Triangle *triangle = malloc(sizeof(Triangle));
    if (triangle == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the base and height of the triangle: ");
    scanf("%lf %lf", &triangle->base, &triangle->height);

    printf("Triangle Area: %.2lf\n", calculate_triangle_area(triangle));
    printf("Triangle Perimeter (equilateral assumption): %.2lf\n", calculate_triangle_perimeter(triangle));

    free(triangle);
}

// Main function
int main() {
    int choice;

    while (1) {
        choice = display_menu();

        switch (choice) {
            case 1:
                handle_circle();
                break;
            case 2:
                handle_rectangle();
                break;
            case 3:
                handle_triangle();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}