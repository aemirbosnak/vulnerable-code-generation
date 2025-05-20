//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

int main() {
    int numRows = 5;
    int numCols = 10;
    char** grid = malloc(numRows * numCols * sizeof(char*));
    for (int i = 0; i < numRows; i++) {
        grid[i] = malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = '?';
        }
    }

    int turn = 0;
    int guessed = 0;
    int correct = 0;

    while (guessed < numRows * numCols) {
        // Print the current state of the grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        // Get a guess from the user
        printf("Guess a letter (A-Z): ");
        char guess = getchar();

        // Check if the guess is correct
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == guess) {
                    correct++;
                    grid[i][j] = 'X'; // Mark the correct letter as X
                }
            }
        }

        // Update the turn and guessed counters
        turn++;
        guessed++;

        // Print the updated grid
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (correct == numRows * numCols) {
            printf("Congratulations! You won the game!\n");
        } else if (guessed == numRows * numCols) {
            printf("Sorry, you ran out of guesses. The correct answer is:\n");
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    printf("%c ", grid[i][j]);
                }
                printf("\n");
            }
        }
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < numRows; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}