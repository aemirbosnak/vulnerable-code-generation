//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

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
            // Print the character at the current position
            if (i == j)
            {
                printf("*");
            }
            else if (i + j == n - 1)
            {
                printf("*");
            }
            else if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
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

    // Get the size of the pattern
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the pattern
    printPattern(n);

    return 0;
}