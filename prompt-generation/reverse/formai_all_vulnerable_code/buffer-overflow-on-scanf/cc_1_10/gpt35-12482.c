//FormAI DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int** ptr;
    int i, rows, cols, count = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for rows of pointers
    ptr = (int**)malloc(rows * sizeof(int *));

    // Allocate memory for each row
    for (i = 0; i < rows; i++)
    {
        ptr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Assign values to the pointer elements and count the number of elements
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr[i][j] = count++;
        }
    }

    // Print out the values
    printf("\nValues of the elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory for each row
    for (i = 0; i < rows; i++)
    {
        free(ptr[i]);
    }

    // Deallocate memory for rows of pointers
    free(ptr);

    return 0;
}