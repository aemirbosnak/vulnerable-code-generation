//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}};
    int player = 1;
    int move_made = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the game is over
    while (!move_made) {
        // Get the move from the player
        int move = rand() % BOARD_SIZE * BOARD_SIZE;

        // Check if the move is valid
        if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0) {
            // Make the move
            board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

            // Check if the player has won
            if (check_win(board, player) == 1) {
                move_made = 1;
            } else {
                // Move made, but no win, so switch to the next player
                player = (player == 1) ? 2 : 1;
            }
        }
    }

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Print the winner
    printf("The winner is: %d", player);

    return 0;
}

int check_win(int **board, int player) {
    // Check for a win in a row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check for a win in a column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check for a win in a diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    } else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    // No win
    return 0;
}