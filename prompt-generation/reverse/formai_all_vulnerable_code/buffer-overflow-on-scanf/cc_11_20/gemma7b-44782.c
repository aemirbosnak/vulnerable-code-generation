//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 3

int main()
{
    int lives = MAX_LIVES;
    char board[2][5] = {{'.','a','a','a','.'}, {'a','a','a','a','a'}};
    int x, y;

    // Game Loop
    while (lives > 0)
    {
        // Get user input
        printf("Enter the coordinates of the ball (x, y): ");
        scanf("%d %d", &x, &y);

        // Check if the input is valid
        if (x < 0 || x >= 2 || y < 0 || y >= 5)
        {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Check if the ball has already been placed there
        if (board[y][x] != '.')
        {
            printf("The ball has already been placed there. Please try again.\n");
            continue;
        }

        // Place the ball in the board
        board[y][x] = 'b';

        // Check if the player has won
        if (board[0][x] == 'b' && board[1][x] == 'b')
        {
            printf("You have won! Congratulations!\n");
            break;
        }

        // Check if the player has lost
        if (board[y][0] == 'b' || board[y][4] == 'b')
        {
            lives--;
            printf("You have lost a life. You have %d lives left.\n", lives);
        }
    }

    // Game Over
    if (lives == 0)
    {
        printf("Game Over. Sorry, you lose.\n");
    }

    return 0;
}