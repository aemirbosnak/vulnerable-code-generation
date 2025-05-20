//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    char board[WIDTH][HEIGHT] = {{' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' '}};

    // Place the paddle
    board[2][0] = 'P';

    // Initialize the ball
    board[1][2] = 'B';

    // Game loop
    while (1)
    {
        // Display the board
        for (int r = 0; r < HEIGHT; r++)
        {
            for (int c = 0; c < WIDTH; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Get the user input
        char input;
        printf("Enter your move (h/l/u/r): ");
        scanf("%c", &input);

        // Move the ball
        switch (input)
        {
            case 'h':
                board[1][2] -= 1;
                break;
            case 'l':
                board[1][2] += 1;
                break;
            case 'u':
                board[1][2] -= 1;
                break;
            case 'r':
                board[1][2] += 1;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if the ball has reached the edge of the board
        if (board[1][2] < 0 || board[1][2] >= WIDTH)
        {
            // Game over
            printf("Game over!\n");
            break;
        }

        // Check if the ball has hit the paddle
        if (board[1][2] == board[2][0] && board[1][2] >= 0)
        {
            // Ball has hit the paddle, so the player loses
            printf("Game over!\n");
            break;
        }
    }

    return 0;
}