//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the pattern
void printPattern(int n)
{
    int i, j, k, l;

    // Iterate over each row
    for (i = 0; i < n; i++)
    {
        // Iterate over each column
        for (j = 0; j < n; j++)
        {
            // Print the appropriate character
            if (i == j)
            {
                printf("* ");
            }
            else if (i + j == n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        // Move to the next line
        printf("\n");
    }

    // Iterate over each row
    for (k = 0; k < n; k++)
    {
        // Iterate over each column
        for (l = 0; l < n; l++)
        {
            // Print the appropriate character
            if (k == l)
            {
                printf("* ");
            }
            else if (k + l == n - 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        // Move to the next line
        printf("\n");
    }
}

// Driver code
int main()
{
    int n;

    // Get the input from the user
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the pattern
    printPattern(n);

    return 0;
}