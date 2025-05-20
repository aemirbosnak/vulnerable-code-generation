//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int **board = NULL;
    int rows = 0, cols = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Game of Life rules

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;

            // Count the number of neighbors
            if (r > 0) neighbors++;
            if (r < rows - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < cols - 1) neighbors++;

            // Update the cell
            board[r][c] = (neighbors == 3) || (neighbors == 2 && board[r][c] == 1);
        }
    }

    // Print the new board

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}