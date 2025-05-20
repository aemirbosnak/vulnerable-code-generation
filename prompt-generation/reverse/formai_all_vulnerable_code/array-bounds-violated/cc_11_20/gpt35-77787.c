//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {false, true} bool;

#define ROWS 10
#define COLS 10

int main() {
    int i, j, count = 0, guessRow, guessCol;
    char board[ROWS][COLS];
    bool gameover = false;
    srand(time(0));

    // Initialize the board randomly with ships and water
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2 == 0 ? 'W' : 'S';
            if (board[i][j] == 'S') count++; // Count the number of ships
        }
    }

    printf("Welcome to Battleship!\n");
    printf("There are %d ships hidden on the board.\n", count);

    // Loop until the game is over
    while (!gameover) {
        // Print the game board
        printf("\n    ");
        for (i = 0; i < COLS; i++) printf("%d ", i);
        printf("\n");
        for (i = 0; i < ROWS; i++) {
            printf("%2d ", i);
            for (j = 0; j < COLS; j++) printf("%c ", board[i][j]);
            printf("\n");
        }

        // Get the user's guess
        printf("Enter a row and column number to guess: ");
        scanf("%d %d", &guessRow, &guessCol);

        // Check if the guess is a hit or a miss
        if (board[guessRow][guessCol] == 'S') {
            printf("HIT!\n");
            board[guessRow][guessCol] = 'X'; // Mark the hit with an X
            count--; // Decrement the number of ships remaining
        } else {
            printf("MISS!\n");
            board[guessRow][guessCol] = 'O'; // Mark the miss with an O
        }

        // Check if the game is over
        if (count == 0) {
            printf("Congratulations, you sank all the ships!\n");
            gameover = true;
        }
    }

    return 0;
}