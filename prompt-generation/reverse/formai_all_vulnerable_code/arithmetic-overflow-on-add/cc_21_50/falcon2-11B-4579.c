//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3];
    int player;
    int computer;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    }

    // Randomly select the first player
    srand(time(0));
    player = rand() % 2;

    while (1) {
        // Print the current board state
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("Player %d's turn\n", player + 1);

        // Player's turn
        printf("Enter your move (row, column): ");
        scanf("%d %d", &board[player % 2][player / 2], &player);

        // Check if the move is valid
        if (board[player % 2][player / 2]!= 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Check if the player has won
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                printf("%d wins!\n", player + 1);
                break;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                printf("%d wins!\n", player + 1);
                break;
            }
        }

        // Check if the player has lost
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
            board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            printf("Player %d loses!\n", (player + 1) % 2);
            break;
        }

        // Check if the board is full
        if (player % 2 == 1) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == 0) {
                        break;
                    }
                }
                if (i == 3) {
                    printf("Draw!\n");
                    break;
                }
            }
        }

        // Switch player
        player = (player + 1) % 2;
    }

    return 0;
}