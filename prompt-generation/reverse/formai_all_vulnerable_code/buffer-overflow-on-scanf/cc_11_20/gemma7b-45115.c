//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 0, cols = 0;
    char ch;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter initial cell values (separated by commas): ");
    scanf("%*c", &ch);
    scanf("%d", board[0][0]);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("Enter value for cell (%d, %d): ", r, c);
            scanf("%d", &board[r][c]);
        }
    }

    printf("Game of Life Simulation:\n");

    for (int t = 0; t < 10; t++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < cols - 1) neighbors++;

                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        printf("Generation %d:\n", t + 1);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}