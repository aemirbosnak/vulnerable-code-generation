//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void play_game(int **board, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int alive = 0;
            if(board[i][j] == 1)
            {
                // Check the 8 neighbors
                if(i > 0) alive++;
                if(j > 0) alive++;
                if(i < size - 1) alive++;
                if(j < size - 1) alive++;
                if(i > 0 && j > 0) alive++;
                if(i > 0 && j < size - 1) alive++;
                if(i < size - 1 && j > 0) alive++;
                if(i < size - 1 && j < size - 1) alive++;

                // Apply the Game of Life rules
                if(alive < 2) board[i][j] = 0;
                else if(alive == 2) board[i][j] = 1;
            }
        }
    }
    return;
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    // Play the game for 5 generations
    for(int gen = 0; gen < 5; gen++)
    {
        play_game(board, size);
    }

    // Print the final board
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}