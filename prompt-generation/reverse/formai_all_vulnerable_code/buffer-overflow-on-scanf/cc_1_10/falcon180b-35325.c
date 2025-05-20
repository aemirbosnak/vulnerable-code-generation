//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define the number of rows and columns in the pattern
#define ROWS 20
#define COLS 30

// Function to print the pattern
void print_pattern(int row, int col) {
    // Check if the current position is within the bounds of the pattern
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        // Print the character based on the row and column position
        if (row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }
}

// Function to print the pattern with a border
void print_pattern_with_border(int row, int col) {
    // Print the border
    printf("+");
    for (int i = 0; i < COLS - 2; i++) {
        printf("-");
    }
    printf("+\n");

    // Print the pattern
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            print_pattern(i, j);
        }
        printf("\n");
    }

    // Print the border
    printf("+");
    for (int i = 0; i < COLS - 2; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    // Get the number of rows and columns from the user
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if the input is valid
    if (rows <= 0 || cols <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    // Print the pattern with a border
    print_pattern_with_border(0, 0);

    return 0;
}