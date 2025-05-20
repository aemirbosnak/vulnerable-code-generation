//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {0}; // 0 means empty, 1 means X, 2 means O
    int player = 1; // Player 1 is X, Player 2 is O
    int moveCount = 0; // Counts the number of moves made
    int winner = 0; // 0 means no winner yet, 1 means Player 1 won, 2 means Player 2 won, 3 means it's a tie
    srand(time(NULL)); // Initializes the random seed

    printf("Welcome to the C Table Game!\n");

    while (winner == 0 && moveCount < 9) { // Game loop
        // Prints the board
        printf("\nCurrent board:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    printf(" - ");
                } else if (board[i][j] == 1) {
                    printf(" X ");
                } else {
                    printf(" O ");
                }
            }
            printf("\n");
        }

        // Makes a move
        int row, col;
        if (player == 1) {
            printf("\nPlayer 1's turn (X).\n");
            printf("Enter the row (1-3): ");
            scanf("%d", &row);
            printf("Enter the column (1-3): ");
            scanf("%d", &col);
        } else {
            printf("\nPlayer 2's turn (O).\n");
            // Random move for player 2
            row = rand() % 3 + 1;
            col = rand() % 3 + 1;
            printf("Player 2 played at row %d, column %d.\n", row, col);
        }

        // Checks if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("\nInvalid move! Positions must be between 1 and 3.\n");
        } else if (board[row-1][col-1] != 0) {
            printf("\nInvalid move! Position already occupied.\n");
        } else {
            board[row-1][col-1] = player;
            moveCount++;

            // Checks win condition
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                    winner = player;
                    break;
                } else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                    winner = player;
                    break;
                }
            }
            if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                winner = player;
            } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
                winner = player;
            }

            // Switches players
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    // Prints the final board and result
    printf("\nFinal board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf(" - ");
            } else if (board[i][j] == 1) {
                printf(" X ");
            } else {
                printf(" O ");
            }
        }
        printf("\n");
    }

    if (winner == 1) {
        printf("\nPlayer 1 (X) has won!\n");
    } else if (winner == 2) {
        printf("\nPlayer 2 (O) has won!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}