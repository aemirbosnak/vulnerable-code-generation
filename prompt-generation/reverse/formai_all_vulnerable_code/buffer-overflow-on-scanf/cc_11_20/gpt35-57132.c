//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

int main()
{
    int grid[ROWS][COLS];
    int player_col = COLS / 2;
    int score = 0;
    int lives = 3;
    int i, j, k;
    srand(time(NULL));

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    while(lives > 0)
    {
        int enemy_row = 0;
        for(j = 0; j < COLS; j++)
        {
            if(grid[enemy_row][j] == 1)
            {
                lives--;
                break;
            }
        }

        grid[enemy_row][player_col] = 0;

        if(lives == 0)
        {
            printf("Game over!\n");
            break;
        }

        for(i = ROWS - 1; i >= 1; i--)
        {
            for(j = 0; j < COLS; j++)
            {
                grid[i][j] = grid[i-1][j];
            }
        }

        for(j = 0; j < COLS; j++)
        {
            grid[0][j] = rand() % 2;
        }

        for(i = 0; i < ROWS; i++)
        {
            for(j = 0; j < COLS; j++)
            {
                if(grid[i][j] == 1)
                {
                    printf("*");
                }
                else if(i == ROWS - 1 && j == player_col)
                {
                    printf("I");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);

        char input;
        printf("Move (left(l)/right(r)):");
        scanf("%c", &input);

        if(input == 'l' && player_col > 0)
        {
            player_col--;
        }
        else if(input == 'r' && player_col < COLS - 1)
        {
            player_col++;
        }
    }

    return 0;
}