//Gemma-7B DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void traverse(int n, int current_position, int **board)
{
    int next_position;

    // Base case
    if (current_position == n - 1)
    {
        board[n - 1][n - 1] = 1;
        return;
    }

    // Iterate over the remaining positions
    for (next_position = 0; next_position < n; next_position++)
    {
        // Check if the position is valid
        if (board[next_position][current_position] == 0)
        {
            // Place the piece in the next position
            board[next_position][current_position] = 1;

            // Recursively traverse the board
            traverse(n, next_position, board);

            // Remove the piece from the next position
            board[next_position][current_position] = 0;
        }
    }
}

int main()
{
    int n;
    int **board;

    printf("Enter the number of rows and columns: ");
    scanf("%d", &n);

    board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    traverse(n, 0, board);

    printf("The solution is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}