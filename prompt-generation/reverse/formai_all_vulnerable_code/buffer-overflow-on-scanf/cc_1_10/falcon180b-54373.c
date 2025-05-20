//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int main() {
    int rows, cols;

    // Get input from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check for valid input
    if (rows <= 0 || cols <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Create a 2D array to store the pattern
    int pattern[MAX_ROWS][MAX_COLS];

    // Initialize the pattern with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern[i][j] = 0;
        }
    }

    // Ask the user for the shape of the pattern
    char shape;
    printf("Enter the shape of the pattern (e.g. X, O, *): ");
    scanf(" %c", &shape);

    // Fill the pattern with the given shape
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                pattern[i][j] = shape;
            }
        }
    }

    // Print the pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}