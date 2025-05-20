//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: shocked
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void draw_board(char board[3][3]) {
    printf("  A B C\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Check for draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return -1;  // Game is not over
            }
        }
    }

    return 0;  // Draw
}

int main() {
    // Initialize the board
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // Set up the players
    char player1 = 'X';
    char player2 = 'O';
    int player = 1;  // Player 1 starts

    // Game loop
    while (1) {
        // Draw the board
        draw_board(board);

        // Get the player's move
        int row, col;
        if (player == 1) {
            printf("Player 1, enter your move (row, column): ");
        } else {
            printf("Player 2, enter your move (row, column): ");
        }
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = player == 1 ? player1 : player2;

        // Check for a winner
        int winner = check_winner(board);
        if (winner != -1) {
            // We have a winner!
            draw_board(board);
            if (winner == 'X') {
                printf("Player 1 wins!\n");
            } else if (winner == 'O') {
                printf("Player 2 wins!\n");
            } else {
                printf("Draw!\n");
            }
            break;
        }

        // Switch players
        player = player == 1 ? 2 : 1;
    }

    return 0;
}