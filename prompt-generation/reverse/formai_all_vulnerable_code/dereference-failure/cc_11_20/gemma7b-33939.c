//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int size = 0;
    int gen_num = 0;

    // Allocate memory for the game board
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the game board
    size = 10;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Generate random patterns
    gen_num = rand() % 5;
    switch (gen_num)
    {
        case 0:
            board[5][5] = 1;
            board[5][6] = 1;
            board[6][5] = 1;
            board[6][6] = 1;
            break;
        case 1:
            board[2][2] = 1;
            board[2][3] = 1;
            board[3][2] = 1;
            board[3][3] = 1;
            break;
        case 2:
            board[1][1] = 1;
            board[1][2] = 1;
            board[2][1] = 1;
            board[2][2] = 1;
            break;
        case 3:
            board[8][8] = 1;
            board[8][9] = 1;
            board[9][8] = 1;
            board[9][9] = 1;
            break;
        case 4:
            board[3][6] = 1;
            board[4][5] = 1;
            board[4][6] = 1;
            board[5][4] = 1;
            break;
    }

    // Print the game board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}