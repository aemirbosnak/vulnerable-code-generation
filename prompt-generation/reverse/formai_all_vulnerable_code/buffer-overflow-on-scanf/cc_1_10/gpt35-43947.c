//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the surprise C Table Game!\n");
    printf("--------------------------------------\n\n");

    // Declare variables
    int numRows, numCols, i, j;
    int **table;
    int sum = 0;

    // Get user input for table size
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    // Allocate memory for the table
    table = (int **) malloc(numRows * sizeof(int *));
    for (i = 0; i < numRows; i++)
        table[i] = (int *) malloc(numCols * sizeof(int));

    // Fill table with random integer values
    srand(time(NULL));
    for (i = 0; i < numRows; i++){
        for (j = 0; j < numCols; j++){
            table[i][j] = rand() % 21;
        }
    }

    // Print table
    printf("\nThe table is:\n");
    for (i = 0; i < numRows; i++){
        for (j = 0; j < numCols; j++){
            printf("%d ", table[i][j]);
            sum += table[i][j];
        }
        printf("\n");
    }

    // Print the sum of all elements in the table
    printf("\nThe sum of all elements in the table is: %d\n\n", sum);

    // Deallocate memory for the table
    for (i = 0; i < numRows; i++)
        free(table[i]);
    free(table);

    printf("That was the surprise C Table Game! Hope you enjoyed it!\n");

    return 0;
}