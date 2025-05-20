//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the game
    char grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }

    // Get the player's name
    char player1[20];
    printf("Player 1, enter your name: ");
    scanf("%s", player1);

    char player2[20];
    printf("Player 2, enter your name: ");
    scanf("%s", player2);

    // Randomly decide who goes first
    srand(time(NULL));
    int turn = rand() % 2;

    // Game loop
    while (1) {
        // Print the game board
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        int row, col;
        if (turn == 0) {
            printf("%s, enter your move (row, col): ", player1);
            scanf("%d %d", &row, &col);
        } else {
            printf("%s, enter your move (row, col): ", player2);
            scanf("%d %d", &row, &col);
        }

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Place the player's symbol on the board
        if (turn == 0) {
            grid[row][col] = 'X';
        } else {
            grid[row][col] = 'O';
        }

        // Check if the game is over
        int winner = check_winner(grid);
        if (winner != -1) {
            if (winner == 0) {
                printf("%s wins!\n", player1);
            } else {
                printf("%s wins!\n", player2);
            }
            break;
        }

        // Switch turns
        turn = (turn + 1) % 2;
    }

    return 0;
}

// Check if the game is over
int check_winner(char grid[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            return grid[i][0] == 'X' ? 0 : 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j] && grid[0][j] != ' ') {
            return grid[0][j] == 'X' ? 0 : 1;
        }
    }

    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return grid[0][0] == 'X' ? 0 : 1;
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return grid[0][2] == 'X' ? 0 : 1;
    }

    // No winner yet
    return -1;
}