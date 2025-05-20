//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function declarations
void printTopHalf(int minLength, int maxLength, int thickness, char symbol, int delayTime);
void printBottomHalf(int minLength, int maxLength, int thickness, char symbol, int delayTime);
void printDiamond(int length, char symbol, int delayTime);

// Main function
int main()
{
    int length;
    char symbol;
    int delayTime;

    // Get user input
    printf("Enter length of diamond: ");
    scanf("%d", &length);

    printf("Enter symbol to use: ");
    scanf(" %c", &symbol);

    printf("Enter delay time (in microseconds): ");
    scanf("%d", &delayTime);

    // Draw diamond
    printDiamond(length, symbol, delayTime);

    return 0;
}

// Helper function to print the top half of the diamond
void printTopHalf(int minLength, int maxLength, int thickness, char symbol, int delayTime)
{
    // Calculate the number of spaces needed in the first row
    int numSpaces = maxLength - minLength;

    // Loop through each row of the top half
    for (int i = 1; i <= thickness; i++)
    {
        // Print the spaces for the current row
        for (int j = 1; j <= numSpaces / 2; j++)
        {
            printf(" ");
            fflush(stdout);
            usleep(delayTime);
        }

        // Print the symbols for the current row
        for (int j = 1; j <= minLength; j++)
        {
            printf("%c", symbol);
            fflush(stdout);
            usleep(delayTime);
        }

        // Print the spaces for the current row
        for (int j = 1; j <= numSpaces / 2; j++)
        {
            printf(" ");
            fflush(stdout);
            usleep(delayTime);
        }

        printf("\n");

        // Update the variables for the next row
        numSpaces -= 2;
        minLength += 2;
    }
}

// Helper function to print the bottom half of the diamond
void printBottomHalf(int minLength, int maxLength, int thickness, char symbol, int delayTime)
{
    // Calculate the number of spaces needed in the first row
    int numSpaces = maxLength - minLength;

    // Loop through each row of the bottom half
    for (int i = thickness; i >= 1; i--)
    {
        // Print the spaces for the current row
        for (int j = 1; j <= numSpaces / 2; j++)
        {
            printf(" ");
            fflush(stdout);
            usleep(delayTime);
        }

        // Print the symbols for the current row
        for (int j = 1; j <= minLength; j++)
        {
            printf("%c", symbol);
            fflush(stdout);
            usleep(delayTime);
        }

        // Print the spaces for the current row
        for (int j = 1; j <= numSpaces / 2; j++)
        {
            printf(" ");
            fflush(stdout);
            usleep(delayTime);
        }

        printf("\n");

        // Update the variables for the next row
        numSpaces += 2;
        minLength -= 2;
    }
}

// Main function to print the diamond
void printDiamond(int length, char symbol, int delayTime)
{
    // Calculate the maximum length of each row
    int maxLength = length * 2 - 1;

    // Print the top half of the diamond
    printTopHalf(1, maxLength, length, symbol, delayTime);

    // Print the bottom half of the diamond
    printBottomHalf(length * 2 - 3, maxLength, length, symbol, delayTime);
}