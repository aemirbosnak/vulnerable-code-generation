//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to print the pattern
void printPattern(int n)
{
    int i, j, k;

    // Iterate over each row
    for (i = 0; i < n; i++)
    {
        // Print spaces before the pattern
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print the pattern
        for (j = 0; j < (2 * i + 1); j++)
        {
            printf("*");
        }

        // Print spaces after the pattern
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print newline character
        printf("\n");
    }

    // Iterate over each row in reverse order
    for (i = n - 1; i >= 0; i--)
    {
        // Print spaces before the pattern
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print the pattern
        for (j = 0; j < (2 * i + 1); j++)
        {
            printf("*");
        }

        // Print spaces after the pattern
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print newline character
        printf("\n");
    }
}

// Driver code
int main()
{
    int n;

    // Get the input from the user
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Print the pattern
    printPattern(n);

    return 0;
}