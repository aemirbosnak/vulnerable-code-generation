//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int board[SIZE][SIZE];
    int player = 1;
    int choice;
    int row, col;
    int flag = 0;

    srand(time(0));

    // Initialize the board with random numbers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Print the initial board
    printf("Initial board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    while (flag == 0) {
        // Print the current player
        if (player == 1) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }

        // Get the player's choice
        printf("Enter your choice (row and column): ");
        scanf("%d %d", &row, &col);

        // Check if the choice is valid
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == 0) {
            // Update the board
            board[row][col] = player;

            // Check for a win condition
            int count = 0;
            for (int i = 0; i < SIZE; i++) {
                if (board[row][i] == player && board[i][col] == player) {
                    count++;
                }
            }

            if (count == 2) {
                printf("Player %d wins!\n", player);
                flag = 1;
            } else if (count == 1) {
                printf("Warning: One more move and player %d will win!\n", 3 - player);
            }

            // Switch to the next player
            player = 3 - player;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}