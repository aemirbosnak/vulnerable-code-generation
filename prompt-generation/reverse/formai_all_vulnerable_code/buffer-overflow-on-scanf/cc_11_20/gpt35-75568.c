//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

int main()
{

    int matrix1[ROW][COL], matrix2[ROW][COL], sum[ROW][COL], mul[ROW][COL];
    int i, j, k;

    srand(time(0));

    printf("[***] CyberPunk Matrix Operation [***]\n\n");
    printf("Enter first %dx%d matrix:\n", ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("Enter the [%d][%d] element: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter second %dx%d matrix:\n", ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("Enter the [%d][%d] element: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMultiplying the Two Matrices..\n\n");

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < COL; k++)
            {
                mul[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The Resultant %dx%d Matrix after Multiplication is:\n\n", ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }

    printf("\nAdding the Two Matrices..\n\n");

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The Resultant %dx%d Matrix after Addition is:\n\n", ROW, COL);

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}