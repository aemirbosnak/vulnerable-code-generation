//Falcon2-11B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(0));

    // Create a 3x3 array to represent the game board
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Display the initial game board
    printf("---------\n");
    printf("|      |      |\n");
    printf("|      |      |\n");
    printf("---------\n");

    // Main game loop
    while (1) {
        // Ask the user for their move
        int row, col;
        printf("Enter your move (row, col): ");
        scanf("%d%d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            printf("Invalid move!\n");
            continue;
        }

        // Update the game board
        board[row][col] = 1;

        // Check if the game is over
        if (checkWinner(board) == 1) {
            break;
        } else if (checkBoardFull(board) == 1) {
            printf("It's a tie!\n");
            break;
        }

        // Display the updated game board
        printf("---------\n");
        printf("|      |      |\n");
        printf("|      |      |\n");
        printf("---------\n");

        // Display the moves made so far
        printf("Player 1: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 1) {
                    printf("X ");
                } else {
                    printf("O ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    // Display the winner (or tie)
    printf("Player %d wins!\n", checkWinner(board) + 1);

    return 0;
}

int checkWinner(int board[3][3]) {
    int cols[3] = {0, 0, 0};
    int rows[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                cols[j]++;
                rows[i]++;
            }
        }
    }

    if (cols[0] == 3) {
        return 1;
    } else if (cols[1] == 3) {
        return 2;
    } else if (cols[2] == 3) {
        return 3;
    } else if (rows[0] == 3) {
        return 1;
    } else if (rows[1] == 3) {
        return 2;
    } else if (rows[2] == 3) {
        return 3;
    }

    return 0;
}

int checkBoardFull(int board[3][3]) {
    int rows[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
            rows[i]++;
        }
    }

    return 1;
}