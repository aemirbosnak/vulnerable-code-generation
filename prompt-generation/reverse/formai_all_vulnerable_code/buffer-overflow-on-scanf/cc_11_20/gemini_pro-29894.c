//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

int check_winner() {
    int i, j;
    char winner = ' ';

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
            break;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner = board[0][i];
            break;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }

    return winner;
}

int main() {
    int i, j;
    char player = 'X';

    // Initialize the board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Play the game
    while (1) {
        // Print the board
        printf("Board:\n");
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        int row, col;
        printf("Player %c's move (row, col): ", player);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Check if the game is over
        char winner = check_winner();
        if (winner != ' ') {
            printf("Player %c wins!\n", winner);
            break;
        }

        // Switch players
        player = player == 'X' ? 'O' : 'X';
    }

    return 0;
}