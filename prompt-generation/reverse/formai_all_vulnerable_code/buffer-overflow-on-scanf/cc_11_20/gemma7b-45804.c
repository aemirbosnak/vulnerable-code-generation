//Gemma-7B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, l, score = 0, highscore = 0;
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    printf("Welcome to Snake Game!\n");
    printf("------------------------\n");

    // Game loop
    while (1) {
        // Display the board
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        printf("Enter your move (w, a, s, d): ");
        char move;
        scanf("%c", &move);

        // Move the snake
        switch (move) {
            case 'w':
                board[l][k] = 'w';
                break;
            case 'a':
                board[l][k] = 'a';
                break;
            case 's':
                board[l][k] = 's';
                break;
            case 'd':
                board[l][k] = 'd';
                break;
            default:
                printf("Invalid move.\n");
                break;
        }

        // Check if the player has won or lost
        if (board[l][k] == 'o') {
            score++;
            printf("You won! Your score is: %d\n", score);
            highscore = score;
            if (highscore > highscore) {
                highscore = score;
            }
            break;
        } else if (board[l][k] == 'x') {
            score = 0;
            printf("You lost. Your score is: %d\n", score);
            break;
        }
    }

    // End game
    printf("Thank you for playing Snake Game!\n");
    printf("Your high score is: %d\n", highscore);

    return 0;
}