//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 5;
    int **arr = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the array
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Play the game
    int round = 0;
    while(round < 5)
    {
        // Get the player's move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Check if the move is valid
        if(row < 0 || row >= size || column < 0 || column >= size)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Mark the move
        arr[row][column] = 1;

        // Check if the player has won
        int winner = check_winner(arr, size);

        // Increment the round
        round++;
    }

    // Free the memory
    for(int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

int check_winner(int **arr, int size)
{
    // Check rows
    for(int i = 0; i < size; i++)
    {
        if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] == arr[3][i] && arr[0][i] == arr[4][i])
        {
            return 1;
        }
    }

    // Check columns
    for(int j = 0; j < size; j++)
    {
        if(arr[j][0] == arr[j][1] && arr[j][0] == arr[j][2] && arr[j][0] == arr[j][3] && arr[j][0] == arr[j][4])
        {
            return 1;
        }
    }

    // Check diagonals
    if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == arr[3][3] && arr[0][0] == arr[4][4])
    {
        return 1;
    }

    // No winner
    return 0;
}