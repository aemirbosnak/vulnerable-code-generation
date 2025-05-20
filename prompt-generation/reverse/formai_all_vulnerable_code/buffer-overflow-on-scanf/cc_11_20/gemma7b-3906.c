//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int **board = NULL;
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    while (1)
    {
        // Get the user's move
        printf("Enter the row number: ");
        int row = scanf("%d") - 1;
        printf("Enter the column number: ");
        int col = scanf("%d") - 1;

        // Check if the move is valid
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Mark the cell as occupied
        board[row][col] = 1;

        // Check if the game is over
        if (board[row][col] == 1)
        {
            printf("Game over!\n");
            break;
        }
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}