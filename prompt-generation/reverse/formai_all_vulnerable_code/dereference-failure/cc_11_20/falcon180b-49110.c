//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int main()
{
    int i,j;
    int *ptr;
    int **matrix;

    //allocate memory for matrix
    matrix = (int**)malloc(sizeof(int*)*SIZE);
    for(i=0; i<SIZE; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*SIZE);
    }

    //initialize matrix with zeros
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }

    //print matrix before adding elements
    printf("Matrix before adding elements:\n");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //add elements to matrix
    ptr = (int*)malloc(sizeof(int)*SIZE*SIZE);
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            matrix[i][j] = ptr[i*SIZE+j];
        }
    }

    //print matrix after adding elements
    printf("\nMatrix after adding elements:\n");
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //free memory allocated for matrix
    for(i=0; i<SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}