//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 5
#define MAX_COL 5

int main()
{

    int board[MAX_ROW][MAX_COL] = {{0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 1, 0, 1, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 0, 0}};

    int row, col;
    char direction;

    printf("Enter row (1-%d): ", MAX_ROW);
    scanf("%d", &row);

    printf("Enter column (1-%d): ", MAX_COL);
    scanf("%d", &col);

    printf("Enter direction (h/w/s/n): ");
    scanf(" %c", &direction);

    switch (direction)
    {
        case 'h':
            if (col > 0)
            {
                board[row][col] = 2;
                board[row][col - 1] = 2;
            }
            break;
        case 'w':
            if (col < MAX_COL - 1)
            {
                board[row][col] = 2;
                board[row][col + 1] = 2;
            }
            break;
        case 's':
            if (row > 0)
            {
                board[row][col] = 2;
                board[row - 1][col] = 2;
            }
            break;
        case 'n':
            if (row < MAX_ROW - 1)
            {
                board[row][col] = 2;
                board[row + 1][col] = 2;
            }
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }

    printf("Board:\n");
    for (row = 0; row < MAX_ROW; row++)
    {
        for (col = 0; col < MAX_COL; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    return 0;
}