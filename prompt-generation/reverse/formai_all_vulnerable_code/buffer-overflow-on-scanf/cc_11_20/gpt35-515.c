//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main()
{
    int board[ROWS][COLS] = {0};
    int row, col, value, moves = 0;

    srand(time(NULL)); // Seed the random number generator

    // Set the initial values on the board randomly
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            value = rand() % 25 + 1; // Random number from 1 to 25
            board[row][col] = value;
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    do {
        // Ask the user for input
        printf("\nEnter row and column (1-4): ");
        scanf("%d%d", &row, &col);

        // Check if the user input is valid
        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
            printf("\nInvalid input. Row and column must be between 1 and 4.");
            continue;
        }

        // Check if the slot is already filled
        if (board[row-1][col-1] != 0) {
            printf("\nSlot is already filled. Try again.");
            continue;
        }

        // Ask the user for the value to put in the slot
        printf("\nEnter value (1-25): ");
        scanf("%d", &value);

        // Check if the value is valid
        if (value < 1 || value > 25) {
            printf("\nInvalid value. Value must be between 1 and 25.");
            continue;
        }

        // Fill the slot on the board with the user's value
        board[row-1][col-1] = value;
        moves++;

        // Print the updated board
        printf("\nUpdated board:\n");
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                printf("%d ", board[row][col]);
            }
            printf("\n");
        }

    // Keep playing until all slots are filled
    } while (moves < ROWS * COLS);

    printf("\nGame over!");

    return 0;
}