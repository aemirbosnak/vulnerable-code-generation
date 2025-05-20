//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: surprised
// C Table Game Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 7

int main() {
    int table[NUM_ROWS][NUM_COLS];
    int row, col, i;

    // Initialize table with random values
    srand(time(NULL));
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            table[row][col] = rand() % 10 + 1;
        }
    }

    // Print table
    printf("  ");
    for (col = 0; col < NUM_COLS; col++) {
        printf("%2d ", col + 1);
    }
    printf("\n");
    for (row = 0; row < NUM_ROWS; row++) {
        printf("%2d ", row + 1);
        for (col = 0; col < NUM_COLS; col++) {
            printf("%2d ", table[row][col]);
        }
        printf("\n");
    }

    // Prompt user for input
    printf("Enter a row and column: ");
    scanf("%d %d", &row, &col);

    // Check if input is valid
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
        printf("Invalid input\n");
        return 1;
    }

    // Print result
    printf("The value at row %d and column %d is %d\n", row + 1, col + 1, table[row][col]);

    return 0;
}