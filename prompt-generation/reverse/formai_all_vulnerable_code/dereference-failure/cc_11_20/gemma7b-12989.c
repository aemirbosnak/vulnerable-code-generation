//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void draw_board(int **board)
{
    int i, j;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int*));
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int*)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the initial game board
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Draw the initial game board
    draw_board(board);

    // Simulate the game of life
    int generation = 0;
    while(1)
    {
        // Calculate the next generation
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                for(int x = -1; x <= 1; x++)
                {
                    for(int y = -1; y <= 1; y++)
                    {
                        if(x == 0 && y == 0) continue;
                        if(board[i + x][j + y] == 1) neighbors++;
                    }
                }
                if(board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                else if(board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Draw the next generation
        draw_board(board);

        // Increment the generation number
        generation++;

        // Check if the game is over
        if(generation >= 10) break;
    }

    // Free the memory
    for(int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}