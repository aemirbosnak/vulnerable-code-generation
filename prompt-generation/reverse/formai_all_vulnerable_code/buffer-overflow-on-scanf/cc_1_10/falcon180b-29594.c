//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum row and column values for the pattern
#define MAX_ROWS 20
#define MAX_COLS 30

// Function to print a single row of the pattern
void print_row(int row, int cols) {
    int i;
    for (i = 0; i < cols; i++) {
        printf("*");
    }
    printf("\n");
}

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random pattern
void generate_pattern(int rows, int cols) {
    int i, j;
    srand(time(NULL));

    // Print the first row with asterisks
    for (j = 0; j < cols; j++) {
        printf("*");
    }
    printf("\n");

    // Generate the rest of the pattern
    for (i = 1; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (rand_int(0, 1) == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Get user input for the number of rows and columns
    printf("Enter the number of rows (1-20): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (1-30): ");
    scanf("%d", &cols);

    // Validate user input
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input. Please enter values between 1 and %d.\n", MAX_ROWS * MAX_COLS);
        return 1;
    }

    // Print the pattern
    generate_pattern(rows, cols);

    return 0;
}