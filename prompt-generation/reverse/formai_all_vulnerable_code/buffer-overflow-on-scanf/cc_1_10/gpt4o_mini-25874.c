//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

#define CIRCLE 0b0001   // 1 - Circle
#define SQUARE 0b0010   // 2 - Square
#define TRIANGLE 0b0100 // 4 - Triangle
#define HEXAGON 0b1000  // 8 - Hexagon

void display_binary_shapes(int shape) {
    printf("Binary representation of shape: %04d\n", shape);
    printf("Shapes represented as follows:\n");
    printf("CIRCLE: %d\n", (shape & CIRCLE) ? 1 : 0);
    printf("SQUARE: %d\n", (shape & SQUARE) ? 1 : 0);
    printf("TRIANGLE: %d\n", (shape & TRIANGLE) ? 1 : 0);
    printf("HEXAGON: %d\n", (shape & HEXAGON) ? 1 : 0);
}

void toggle_shape(int *shape, int new_shape) {
    *shape ^= new_shape; // Toggle the new shape's state
    printf("\nShape toggled!\n");
}

void display_menu() {
    printf("\nShape Shifting Program:\n");
    printf("1. Add Circle\n");
    printf("2. Remove Circle\n");
    printf("3. Add Square\n");
    printf("4. Remove Square\n");
    printf("5. Add Triangle\n");
    printf("6. Remove Triangle\n");
    printf("7. Add Hexagon\n");
    printf("8. Remove Hexagon\n");
    printf("9. Display Current Shape\n");
    printf("0. Exit\n");
}

int main() {
    int current_shape = 0b0000; // Start with no shapes
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Circle
                toggle_shape(&current_shape, CIRCLE);
                break;
            case 2: // Remove Circle
                toggle_shape(&current_shape, CIRCLE);
                break;
            case 3: // Add Square
                toggle_shape(&current_shape, SQUARE);
                break;
            case 4: // Remove Square
                toggle_shape(&current_shape, SQUARE);
                break;
            case 5: // Add Triangle
                toggle_shape(&current_shape, TRIANGLE);
                break;
            case 6: // Remove Triangle
                toggle_shape(&current_shape, TRIANGLE);
                break;
            case 7: // Add Hexagon
                toggle_shape(&current_shape, HEXAGON);
                break;
            case 8: // Remove Hexagon
                toggle_shape(&current_shape, HEXAGON);
                break;
            case 9: // Display Current Shape
                display_binary_shapes(current_shape);
                break;
            case 0: // Exit
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid selection! Please enter a number between 0 and 9.\n");
        }
    }

    return 0;
}