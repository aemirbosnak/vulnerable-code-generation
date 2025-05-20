//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 5
#define UP_BOUND 0
#define DOWN_BOUND 3

int main()
{
    int x, y, score = 0, game_over = 0;
    char board[5][4] = {{'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'},
                              {'.','.'}};

    // Initialize the random number generator
    srand(time(NULL));

    // Place the invader
    board[2][1] = 'I';

    // Game loop
    while (!game_over)
    {
        // Display the board
        for (y = UP_BOUND; y <= DOWN_BOUND; y++)
        {
            for (x = LEFT_BOUND; x <= RIGHT_BOUND; x++)
            {
                printf("%c ", board[y][x]);
            }
            printf("\n");
        }

        // Get the user's input
        int move = getchar();

        // Move the invader
        switch (move)
        {
            case 'A':
                board[y][x - 1] = 'I';
                board[y][x] = '.';
                break;
            case 'D':
                board[y][x + 1] = 'I';
                board[y][x] = '.';
                break;
            case 'S':
                board[y + 1][x] = 'I';
                board[y][x] = '.';
                break;
            case 'W':
                board[y - 1][x] = 'I';
                board[y][x] = '.';
                break;
        }

        // Check if the invader has moved off the board
        if (board[y][x] == 'I')
        {
            game_over = 1;
        }

        // Increment the score if the invader has moved to the right side of the board
        if (board[y][x] == 'I' && x == RIGHT_BOUND)
        {
            score++;
        }
    }

    // Game over message
    printf("Game over! Your score is: %d", score);

    return 0;
}