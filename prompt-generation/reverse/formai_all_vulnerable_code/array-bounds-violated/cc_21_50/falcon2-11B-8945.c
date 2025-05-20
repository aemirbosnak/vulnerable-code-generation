//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    int currentPlayer = 1; // 1 for player 1, -1 for player 2
    int winningCombination[3][3] = {{0, 1, 2}, {1, 2, 3}, {0, 2, 4}, {1, 4, 5}, {2, 4, 6}, {0, 3, 6}, {1, 3, 5}, {2, 3, 4}};
    int winner = 0;

    // Print the initial board
    printf("---------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                printf("| ");
            else
                printf("| %d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------\n");

    while (winner == 0) {
        // Print the current board
        printf("---------\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0)
                    printf("| ");
                else
                    printf("| %d ", board[i][j]);
            }
            printf("|\n");
        }
        printf("---------\n");

        // Get player's move
        int move = 0;
        printf("Player %d's turn.\n", currentPlayer == 1? 1 : -1);
        printf("Enter a number between 1 and 9: ");
        scanf("%d", &move);
        while (move < 1 || move > 9) {
            printf("Invalid move. Enter a number between 1 and 9: ");
            scanf("%d", &move);
        }

        // Make the move
        int x = move / 3;
        int y = move % 3;
        board[x][y] = currentPlayer;

        // Check if the player won
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0) {
                winner = board[i][0];
                break;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= 0) {
                winner = board[0][i];
                break;
            }
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
                winner = board[0][0];
                break;
            }
        }

        // Switch player
        if (winner == 1) {
            currentPlayer = -1;
        } else if (winner == -1) {
            currentPlayer = 1;
        } else if (currentPlayer == 1) {
            currentPlayer = -1;
        } else {
            currentPlayer = 1;
        }
    }

    // Print the final board
    printf("---------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0)
                printf("| ");
            else
                printf("| %d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("---------\n");

    return 0;
}