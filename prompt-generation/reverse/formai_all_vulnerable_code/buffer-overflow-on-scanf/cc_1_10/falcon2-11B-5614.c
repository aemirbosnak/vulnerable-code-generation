//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to print a pattern
void printPattern(int n)
{
    // Initializing the current position
    int currentPosition = 1;
    int i;

    // Print spaces before pattern
    for (i = 1; i <= n; i++)
    {
        printf(" ");
    }

    // Print the pattern
    for (i = 1; i <= n; i++)
    {
        // Print stars for current position
        for (int j = 1; j <= currentPosition; j++)
        {
            printf("*");
        }

        // Move to the next position
        currentPosition = currentPosition + 1;

        // Print spaces for the next position
        for (int j = 1; j <= (n - currentPosition); j++)
        {
            printf(" ");
        }

        // Print newline character to move to the next line
        printf("\n");
    }
}

// Function to print a pattern
void printPattern1(int n)
{
    // Initializing the current position
    int currentPosition = 1;
    int i;

    // Print spaces before pattern
    for (i = 1; i <= n; i++)
    {
        printf(" ");
    }

    // Print the pattern
    for (i = 1; i <= n; i++)
    {
        // Print stars for current position
        for (int j = 1; j <= currentPosition; j++)
        {
            printf("*");
        }

        // Move to the next position
        currentPosition = currentPosition + 1;

        // Print spaces for the next position
        for (int j = 1; j <= (n - currentPosition); j++)
        {
            printf(" ");
        }

        // Print newline character to move to the next line
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    printPattern(n);
    printPattern1(n);
    return 0;
}