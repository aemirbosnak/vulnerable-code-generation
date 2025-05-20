//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main()
{
    int x = 5, y = 5, direction = RIGHT, board[25] = {0}, score = 0;
    char c;

    // Draw the initial board
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%c ", board[i * 5 + j] ? '#' : '.');
        }
        printf("\n");
    }

    // Game loop
    while(!board[x * 5 + y] && direction != DOWN)
    {
        // Get the user input
        c = getchar();

        // Move the paddle
        switch(c)
        {
            case 'w': direction = UP; break;
            case 's': direction = DOWN; break;
            case 'a': direction = LEFT; break;
            case 'd': direction = RIGHT; break;
        }

        // Update the paddle position
        switch(direction)
        {
            case UP: y--; break;
            case DOWN: y++; break;
            case LEFT: x--; break;
            case RIGHT: x++; break;
        }

        // Draw the updated board
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%c ", board[i * 5 + j] ? '#' : '.');
            }
            printf("\n");
        }

        // Increment the score if the ball reaches the paddle
        if(board[x * 5 + y] && board[x * 5 + y] == 1)
        {
            score++;
            board[x * 5 + y] = 0;
        }
    }

    // Game over
    printf("Game Over! Your score is: %d", score);

    return 0;
}