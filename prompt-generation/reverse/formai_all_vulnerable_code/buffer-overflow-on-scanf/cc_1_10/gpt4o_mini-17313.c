//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_line(char *title) {
    printf("\n---------------------------------\n");
    printf("%s\n", title);
    printf("---------------------------------\n");
}

void calculate_circle_area(float radius) {
    float area = PI * radius * radius;
    printf("Area of the circle with radius %.2f is: %.2f\n", radius, area);
}

void calculate_rectangle_area(float length, float width) {
    float area = length * width;
    printf("Area of the rectangle with length %.2f and width %.2f is: %.2f\n", length, width, area);
}

void calculate_triangle_area(float base, float height) {
    float area = 0.5 * base * height;
    printf("Area of the triangle with base %.2f and height %.2f is: %.2f\n", base, height, area);
}

void calculate_square_area(float side) {
    float area = side * side;
    printf("Area of the square with side %.2f is: %.2f\n", side, area);
}

void display_options() {
    printf("Please choose a shape to calculate the area:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Square\n");
    printf("5. Exit\n");
}

int main() {
    float radius, length, width, base, height, side;
    int choice;

    do {
        // Display options for the user
        draw_line("Area Calculator");
        display_options();

        // Prompt user for choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Perform calculations based on the choice
        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%f", &radius);
                calculate_circle_area(radius);
                break;

            case 2:
                printf("Enter the length of the rectangle: ");
                scanf("%f", &length);
                printf("Enter the width of the rectangle: ");
                scanf("%f", &width);
                calculate_rectangle_area(length, width);
                break;

            case 3:
                printf("Enter the base of the triangle: ");
                scanf("%f", &base);
                printf("Enter the height of the triangle: ");
                scanf("%f", &height);
                calculate_triangle_area(base, height);
                break;

            case 4:
                printf("Enter the side of the square: ");
                scanf("%f", &side);
                calculate_square_area(side);
                break;

            case 5:
                printf("Thank you for using the Area Calculator! Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }

        printf("\n"); // Add a new line for clarity

    } while (choice != 5);

    return 0;
}