//FormAI DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

int main()
{
    int i, j, rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Printing the upper section of the C
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= columns; j++)
        {
            if ((j == 1 && i != rows) || (i == 1 || i == rows && j > 1 && j < columns))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    // Printing the lower section of the C
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= columns; j++)
        {
            if ((j == 1 && i != 1 && i != rows) || (i > 1 && i < rows && j == columns))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}