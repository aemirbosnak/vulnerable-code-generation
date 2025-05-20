//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Helper function to print error message and exit program
void error(char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main() {
    // Welcome message
    printf("Welcome to the Shape Shifting Error Handler!\n");

    // Get user input
    int shape;
    printf("Select a shape:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("> ");
    scanf("%d", &shape);

    // Handle invalid input
    if (shape < 1 || shape > 3) {
        error("Invalid shape selected. Please try again.");
    }

    // Get shape values
    float base, height, width, radius;
    switch (shape) {
        case 1:
            printf("Enter the base of the triangle: ");
            if (scanf("%f", &base) != 1 || base <= 0) {
                error("Invalid base value entered. Please try again.");
            }
            printf("Enter the height of the triangle: ");
            if (scanf("%f", &height) != 1 || height <= 0) {
                error("Invalid height value entered. Please try again.");
            }
            printf("Area of the triangle: %f\n", base * height / 2);
            break;
        case 2:
            printf("Enter the width of the rectangle: ");
            if (scanf("%f", &width) != 1 || width <= 0) {
                error("Invalid width value entered. Please try again.");
            }
            printf("Enter the height of the rectangle: ");
            if (scanf("%f", &height) != 1 || height <= 0) {
                error("Invalid height value entered. Please try again.");
            }
            printf("Area of the rectangle: %f\n", width * height);
            break;
        case 3:
            printf("Enter the radius of the circle: ");
            if (scanf("%f", &radius) != 1 || radius <= 0) {
                error("Invalid radius value entered. Please try again.");
            }
            printf("Area of the circle: %f\n", 3.14 * radius * radius);
            break;
    }

    // Exit program with success status
    return 0;
}