//Code Llama-13B DATASET v1.0 Category: Table Game ; Style: lively
/*
 *  Table Game Example Program
 *  Written in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 5

int main() {
    // Initialize the table
    int table[TABLE_SIZE][TABLE_SIZE];

    // Initialize the random seed
    srand(time(NULL));

    // Fill the table with random numbers
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = rand() % 100;
        }
    }

    // Print the table
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            printf("%3d ", table[i][j]);
        }
        printf("\n");
    }

    // Ask the user for a row and column
    int row, col;
    printf("Enter a row: ");
    scanf("%d", &row);
    printf("Enter a column: ");
    scanf("%d", &col);

    // Check if the row and column are valid
    if (row < 0 || row >= TABLE_SIZE || col < 0 || col >= TABLE_SIZE) {
        printf("Invalid row and column!\n");
        return 1;
    }

    // Print the value at the specified row and column
    printf("The value at (%d, %d) is %d\n", row, col, table[row][col]);

    return 0;
}