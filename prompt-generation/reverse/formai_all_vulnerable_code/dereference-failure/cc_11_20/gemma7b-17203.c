//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void game_of_life(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check the 8 neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < size) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < size) neighbors++;
            if (r - 1 && c - 1 >= 0) neighbors++;
            if (r - 1 && c + 1 < size) neighbors++;
            if (r + 1 && c - 1 >= 0) neighbors++;
            if (r + 1 && c + 1 < size) neighbors++;

            // Apply the rules
            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int size = MAX;
    int **board = (int**)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;
    board[2][1] = 1;

    // Game of Life
    game_of_life(board, size);

    // Print the result
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++) free(board[i]);
    free(board);

    return 0;
}