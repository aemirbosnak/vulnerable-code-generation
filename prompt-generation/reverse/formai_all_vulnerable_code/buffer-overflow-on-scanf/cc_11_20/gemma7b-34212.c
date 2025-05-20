//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n_ships = 0, n_missiles = 0, game_over = 0;
    char board[10][10] = {{0}};

    // Initialize the board with ships and missiles
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 'S';
                n_ships++;
            } else if (rand() % 3 == 0) {
                board[i][j] = 'M';
                n_missiles++;
            }
        }
    }

    // Print the board
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Game loop
    while (!game_over) {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Check if the move is valid
        if (row < 0 || row >= 10 || column < 0 || column >= 10) {
            printf("Invalid move.\n");
        } else if (board[row][column] == 'O') {
            printf("You already attacked that spot.\n");
        } else if (board[row][column] == 'S') {
            board[row][column] = 'O';
            n_ships--;
            printf("You sunk a ship!\n");
        } else {
            board[row][column] = 'O';
            n_missiles++;
            printf("Miss.\n");
        }

        // Check if the game is over
        if (n_ships == 0) {
            game_over = 1;
            printf("Congratulations! You won!\n");
        } else if (n_missiles == 10) {
            game_over = 1;
            printf("Sorry, you lost.\n");
        }
    }

    return 0;
}