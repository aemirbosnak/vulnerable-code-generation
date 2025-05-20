//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to print the pattern
void printPattern(int n)
{
    // Iterate over each row
    for (int i = 0; i < n; i++)
    {
        // Print spaces for the current row
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print the stars for the current row
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }

    // Iterate over each row in reverse order
    for (int i = n - 2; i >= 0; i--)
    {
        // Print spaces for the current row
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print the stars for the current row
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

// Main function
int main()
{
    // Get the size of the pattern from the user
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the pattern
    printPattern(n);

    return 0;
}