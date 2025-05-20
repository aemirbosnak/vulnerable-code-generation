//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// Recursive function to print the C pattern
void printC(int rows, int cols, int currentRow)
{
    // Base case
    if(currentRow == rows)
    {
        return;
    }

    // Recursive case
    else
    {
        int i;

        // Print first column
        printf("*");

        // Print middle column
        for(i=0; i < cols-2; i++)
        {
            if(currentRow == 0 || currentRow == rows-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        // Print last column
        printf("*\n");

        // Recursively call the function
        printC(rows, cols, currentRow+1);
    }
}

int main()
{
    int rows, cols;

    // Get input from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Print the C pattern
    printf("\nPrinting C Pattern:\n\n");
    printC(rows, cols, 0);

    return 0;
}