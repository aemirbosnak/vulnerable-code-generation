//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10
#define MAX_VALUE 100
#define MIN_VALUE 1

int main()
{
    int i, j, rows, cols;
    int **matrix;
    int sum = 0;
    double mean, variance;
    srand(time(NULL));

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            sum += matrix[i][j];
        }
    }

    mean = (double)sum / (rows * cols);

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            variance += pow((matrix[i][j] - mean), 2);
        }
    }

    variance = variance / (rows * cols);

    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}