//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    int score = 0;
    int lives = 3;
    char board[4][4] = {{' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' '}};

    // Game loop
    while (lives > 0) {
        // Display the board
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user's move
        int move = -1;
        printf("Enter your move (1-16): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 16) {
            printf("Invalid move.\n");
            continue;
        }

        // Place the user's piece on the board
        board[move / 4][move % 4] = 'X';

        // Check if the user has won
        if (board[0][0] == 'X' || board[0][1] == 'X' || board[0][2] == 'X' || board[0][3] == 'X' ||
            board[1][0] == 'X' || board[1][1] == 'X' || board[1][2] == 'X' || board[1][3] == 'X' ||
            board[2][0] == 'X' || board[2][1] == 'X' || board[2][2] == 'X' || board[2][3] == 'X' ||
            board[3][0] == 'X' || board[3][1] == 'X' || board[3][2] == 'X' || board[3][3] == 'X') {
            score++;
            printf("You won! Your score is: %d\n", score);
            break;
        }

        // Check if the user has lost
        if (board[0][0] == 'O' || board[0][1] == 'O' || board[0][2] == 'O' || board[0][3] == 'O' ||
            board[1][0] == 'O' || board[1][1] == 'O' || board[1][2] == 'O' || board[1][3] == 'O' ||
            board[2][0] == 'O' || board[2][1] == 'O' || board[2][2] == 'O' || board[2][3] == 'O' ||
            board[3][0] == 'O' || board[3][1] == 'O' || board[3][2] == 'O' || board[3][3] == 'O') {
            lives--;
            printf("You lost. Your lives are: %d\n", lives);
        }
    }

    // Game over
    return 0;
}