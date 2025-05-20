//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rows and columns
#define MAX_ROWS 20
#define MAX_COLS 20

// Function to print the pattern
void print_pattern(int rows, int cols) {
    int i, j;

    // Loop through each row
    for(i = 0; i < rows; i++) {
        // Print spaces before the pattern
        for(j = 0; j < cols - 2; j++) {
            printf(" ");
        }

        // Print the pattern
        printf("*");

        // Print spaces after the pattern
        for(j = 0; j < cols - 2; j++) {
            printf(" ");
        }

        // Move to the next line
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if the input is valid
    if(rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input. Please enter valid values.\n");
        return 1;
    }

    // Print the pattern
    printf("*\n");
    for(int i = 0; i < rows - 2; i++) {
        printf("* ");
    }
    printf("\n*\n");

    // Call the function to print the pattern
    print_pattern(rows, cols);

    return 0;
}