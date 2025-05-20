//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>

//Define constants for matrix size
#define ROWS 5
#define COLS 5

int main()
{
    //Initialize matrix
    int matrix[ROWS][COLS];

    //Initialize variables to hold input values
    int row, col, val;

    //Loop through matrix and prompt user for input
    printf("Enter values for matrix:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("Enter value for matrix[%d][%d]: ", row, col);
            scanf("%d", &val);
            matrix[row][col] = val;
        }
    }

    //Print matrix
    printf("\nMatrix:\n");
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    //Create graph representation of matrix
    printf("\nGraph:\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("%d -> ", row);
        for(col = 0; col < COLS; col++)
        {
            if(matrix[row][col] != 0)
            {
                printf("%d ", col);
            }
        }
        printf("\n");
    }

    return 0;
}