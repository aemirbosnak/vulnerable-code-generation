//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int x, y, score = 0, game_over = 0;
    char board[WIDTH][HEIGHT] = {{'-', '-', '-', '-', '-', '-'},
                              {'-', 'O', 'O', 'O', '-', '-'},
                              {'-', 'O', 'O', 'O', 'O', '-'},
                              {'-', 'O', 'O', 'O', 'O', '-'},
                              {'-', '-', '-', '-', '-', '-'}};

    system("clear");
    printf("   |---||---|\n");
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("|%c ", board[x][y]);
        }
        printf("|\n");
    }
    printf("   |---||---|\n");
    printf("Score: %d\n", score);
    printf("Game Over: %d\n", game_over);

    // Game Logic
    // Movement, Collision Detection, Score Increment, Game Over Logic

    // Update Board
    board[x][y] = 'O';

    // Display Board
    system("clear");
    printf("   |---||---|\n");
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("|%c ", board[x][y]);
        }
        printf("|\n");
    }
    printf("   |---||---|\n");
    printf("Score: %d\n", score);
    printf("Game Over: %d\n", game_over);

    return 0;
}