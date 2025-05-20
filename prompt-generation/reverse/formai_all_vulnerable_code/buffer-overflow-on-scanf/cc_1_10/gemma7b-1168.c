//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;
    char input;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int *)malloc(rows * cols * sizeof(int));
    if (board == NULL)
    {
        printf("Error allocating memory.\n");
        return 1;
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    printf("Enter 'S' to simulate the game or 'Q' to quit: ");
    scanf(" %c", &input);

    while (input != 'Q')
    {
        printf("Enter the row number: ");
        int rowNum;
        scanf("%d", &rowNum);

        printf("Enter the column number: ");
        int colNum;
        scanf("%d", &colNum);

        board[rowNum][colNum] = 1;

        printf("Enter 'S' to simulate the game or 'Q' to quit: ");
        scanf(" %c", &input);
    }

    free(board);

    return 0;
}