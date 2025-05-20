//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

void Matrix_Operations(int **arr, int r, int c)
{
    int i, j, k;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            arr[i][j] = 0;
            for (k = 0; k < r; k++)
            {
                if (k != i)
                {
                    arr[i][j] += arr[k][j];
                }
            }
        }
    }

    return;
}

int main()
{
    int **arr = NULL;
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    arr = (int **)malloc(r * sizeof(int *) + c * sizeof(int));
    for (r = 0; r < r; r++)
    {
        arr[r] = (int *)malloc(c * sizeof(int));
    }

    Matrix_Operations(arr, r, c);

    printf("The matrix after operations is:\n");
    for (r = 0; r < r; r++)
    {
        for (c = 0; c < c; c++)
        {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}