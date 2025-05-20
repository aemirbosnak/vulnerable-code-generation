//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>

#define ROWS 8
#define COLS 8
#define EMPTY '-'

int main () {
    char board[ROWS][COLS];
    int player = 1;
    int row, col;
    int winner = 0;
    char playerOnePiece = 'O';
    char playerTwoPiece = 'X';
    int numPiecesPlayerOne = 12;
    int numPiecesPlayerTwo = 12;

    // Initialize the board with empty spots
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = EMPTY;
        }
    }

    // Loop until there is a winner
    while (!winner) {
        printf("Player %d's turn\n", player);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row, &col);

        if (board[row][col] == playerOnePiece) {
            if (player == 1) {
                // Update the board and the number of pieces for the player
                board[row][col] = EMPTY;
                board[row-1][col-1] = playerOnePiece;
                numPiecesPlayerOne--;

                // Check if the player has won
                if (numPiecesPlayerOne == 0) {
                    winner = player;
                    printf("Player %d has won!\n", winner);
                }

                // Switch to the next player
                player = 2;
            }
            else {
                printf("Wrong player!\n");
            }
        }
        else if (board[row][col] == playerTwoPiece) {
            if (player == 2) {
                // Update the board and the number of pieces for the player
                board[row][col] = EMPTY;
                board[row+1][col+1] = playerTwoPiece;
                numPiecesPlayerTwo--;

                // Check if the player has won
                if (numPiecesPlayerTwo == 0) {
                    winner = player;
                    printf("Player %d has won!\n", winner);
                }

                // Switch to the next player
                player = 1;
            }
            else {
                printf("Wrong player!\n");
            }
        }
        else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}