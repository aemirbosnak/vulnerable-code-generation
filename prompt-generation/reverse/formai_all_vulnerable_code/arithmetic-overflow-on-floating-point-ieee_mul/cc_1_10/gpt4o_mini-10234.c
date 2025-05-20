//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: real-life
#include <stdio.h>
#include <math.h>

#define PI 3.14159

// Function prototypes
float calculate_rectangle_area(float width, float height);
float calculate_rectangle_perimeter(float width, float height);
float calculate_circle_area(float radius);
float calculate_circle_perimeter(float radius);
float calculate_triangle_area(float base, float height);
float calculate_triangle_perimeter(float side1, float side2, float side3);

void display_menu();

int main() {
    int choice;
    float width, height, radius, base, side1, side2, side3;

    while (1) {
        display_menu();
        printf("Enter your choice (1-5, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Rectangle
                printf("Enter width and height of the rectangle: ");
                scanf("%f %f", &width, &height);
                printf("Rectangle Area: %.2f\n", calculate_rectangle_area(width, height));
                printf("Rectangle Perimeter: %.2f\n", calculate_rectangle_perimeter(width, height));
                break;

            case 2: // Circle
                printf("Enter radius of the circle: ");
                scanf("%f", &radius);
                printf("Circle Area: %.2f\n", calculate_circle_area(radius));
                printf("Circle Perimeter (Circumference): %.2f\n", calculate_circle_perimeter(radius));
                break;

            case 3: // Triangle
                printf("Enter base and height of the triangle: ");
                scanf("%f %f", &base, &height);
                printf("Triangle Area: %.2f\n", calculate_triangle_area(base, height));
                
                printf("Enter lengths of the three sides of the triangle: ");
                scanf("%f %f %f", &side1, &side2, &side3);
                printf("Triangle Perimeter: %.2f\n", calculate_triangle_perimeter(side1, side2, side3));
                break;

            case 0: // Exit
                 printf("Exiting the program. Goodbye!\n");
                 return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n"); // Blank line for better readability
    }

    return 0;
}

float calculate_rectangle_area(float width, float height) {
    return width * height;
}

float calculate_rectangle_perimeter(float width, float height) {
    return 2 * (width + height);
}

float calculate_circle_area(float radius) {
    return PI * radius * radius;
}

float calculate_circle_perimeter(float radius) {
    return 2 * PI * radius;
}

float calculate_triangle_area(float base, float height) {
    return 0.5 * base * height;
}

float calculate_triangle_perimeter(float side1, float side2, float side3) {
    return side1 + side2 + side3;
}

void display_menu() {
    printf("Geometric Shape Calculator\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("0. Exit\n");
}