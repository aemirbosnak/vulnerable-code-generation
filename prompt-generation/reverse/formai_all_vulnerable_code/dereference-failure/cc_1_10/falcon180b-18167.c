//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int rows, cols, i, j, k, rand_num, sum;
    int **arr;
    srand(time(NULL));

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    arr = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        for(j=0; j<cols; j++)
        {
            rand_num = rand() % 100;
            arr[i][j] = rand_num;
        }
    }

    printf("\nMatrix:\n");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of elements in each row:\n");
    for(i=0; i<rows; i++)
    {
        sum = 0;
        for(j=0; j<cols; j++)
        {
            sum += arr[i][j];
        }
        printf("%d\n", sum);
    }

    for(i=0; i<rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}