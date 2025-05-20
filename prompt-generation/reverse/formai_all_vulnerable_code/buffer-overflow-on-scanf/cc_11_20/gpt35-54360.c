//FormAI DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

int main() {
    int values[ROWS * COLUMNS];
    int row, column, temp;
    int i, j;

    srand(time(NULL));

    // Initialize the game board with random values
    for (i = 0; i < ROWS * COLUMNS; i++) {
        values[i] = rand() % 100;
    }

    // Shuffle the game board using the Fisher-Yates shuffle algorithm
    for (i = ROWS * COLUMNS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Print the shuffled game board
    printf("Let's play the Memory Game!\n\n");
    for (row = 0; row < ROWS; row++) {
        for (column = 0; column < COLUMNS; column++) {
            printf("%d ", values[row * COLUMNS + column]);
        }
        printf("\n");
    }
    printf("\n");

    // Main game loop
    int turns = 0;
    int firstPick, secondPick;
    int revealed[ROWS * COLUMNS];
    for (i = 0; i < ROWS * COLUMNS; i++) {
        revealed[i] = 0;
    }

    while (1) {
        printf("Enter two coordinates to flip over two cards: ");
        scanf("%d %d", &row, &column);

        // Input validation
        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (revealed[row * COLUMNS + column] == 1) {
            printf("That card has already been revealed. Try again.\n");
            continue;
        }

        // Reveal the selected card and print the updated game board
        revealed[row * COLUMNS + column] = 1;
        printf("\n");
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                if (revealed[i * COLUMNS + j] == 1) {
                    printf("%d ", values[i * COLUMNS + j]);
                }
                else {
                    printf("X ");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Check if two cards have been revealed and compare their values
        turns++;
        if (turns % 2 == 1) {
            firstPick = row * COLUMNS + column;
        }
        else {
            secondPick = row * COLUMNS + column;
            if (values[firstPick] != values[secondPick]) {
                // If the two cards don't match, hide them again
                revealed[firstPick] = 0;
                revealed[secondPick] = 0;
                printf("Cards don't match. Try again.\n");
            }
            else {
                printf("Match!\n");
                if (turns == ROWS * COLUMNS) {
                    // If all cards have been matched, end the game
                    printf("You win!\n");
                    return 0;
                }
            }
        }
    }
}