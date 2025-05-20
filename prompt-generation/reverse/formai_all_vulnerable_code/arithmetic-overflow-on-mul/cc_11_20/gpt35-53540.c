//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,n,row,col,moves=0;
    int **matrix; // Dynamic allocation of 2D array
    printf("Enter the dimensions of the matrix (rows, columns): ");
    scanf("%d%d",&row,&col);
    matrix = (int **)malloc(row * sizeof(int *));
    for (i=0;i<row;i++)
        matrix[i] = (int *)malloc(col * sizeof(int));
    n=row*col; // Total number of elements in the matrix
    // Initializing the matrix elements
    for (i=0;i<row;i++)
        for (j=0;j<col;j++)
            matrix[i][j]=-1;

    srand((unsigned)time(NULL)); // Random number generator
    while (n>0)
    {
        printf("Moves: %d\n",moves);
        for (i=0;i<row;i++)
        {
            for (j=0;j<col;j++)
            {
                if (matrix[i][j]!=-1)
                    printf("%d\t",matrix[i][j]);
                else
                    printf("*\t");
            }
            printf("\n");
        }
        printf("Enter the row and column number (separated by space): ");
        scanf("%d%d",&i,&j);
        if (i>=row||j>=col||i<0||j<0)
        {
            printf("Invalid input! Please enter valid row and column numbers.\n");
            continue;
        }
        if (matrix[i][j]!=-1)
        {
            printf("Invalid input! Element already selected.\n");
            continue;
        }
        matrix[i][j]=rand()%10; // Generating random number between 0 and 9
        n--; // Decrementing the element counter
        moves++; // Incrementing the move counter
    }
    printf("Game over! You took %d moves to reveal all the elements.\n",moves);
    return 0;
}