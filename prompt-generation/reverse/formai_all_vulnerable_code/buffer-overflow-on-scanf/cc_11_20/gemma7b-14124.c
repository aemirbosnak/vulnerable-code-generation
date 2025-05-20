//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDLES 10

int main() {
    int numCandles = MAX_CANDLES;
    char board[MAX_CANDLES][MAX_CANDLES] = {{0}};

    // Initialize the board
    for (int r = 0; r < MAX_CANDLES; r++) {
        for (int c = 0; c < MAX_CANDLES; c++) {
            board[r][c] = '-';
        }
    }

    // Place the candles
    board[2][3] = 'x';
    board[4][4] = 'x';

    // Play the game
    int move = 0;
    char moveDir = ' ';

    // Loop until the game is over
    while (numCandles > 0) {
        // Get the user's move
        printf("Enter your move (N/S/E/W): ");
        scanf("%c", &moveDir);

        // Validate the move
        if (moveDir != 'N' && moveDir != 'S' && moveDir != 'E' && moveDir != 'W') {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        switch (moveDir) {
            case 'N':
                board[move][0] = 'x';
                move++;
                break;
            case 'S':
                board[move][MAX_CANDLES - 1] = 'x';
                move++;
                break;
            case 'E':
                board[0][move] = 'x';
                move++;
                break;
            case 'W':
                board[MAX_CANDLES - 1][move] = 'x';
                move++;
                break;
        }

        // Check if the move was successful
        if (board[move][move] != 'x') {
            printf("Invalid move.\n");
            continue;
        }

        // Update the number of candles
        numCandles--;

        // Print the board
        for (int r = 0; r < MAX_CANDLES; r++) {
            for (int c = 0; c < MAX_CANDLES; c++) {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (numCandles == 0) {
            printf("You won!\n");
        } else {
            printf("Continue.\n");
        }
    }

    return 0;
}