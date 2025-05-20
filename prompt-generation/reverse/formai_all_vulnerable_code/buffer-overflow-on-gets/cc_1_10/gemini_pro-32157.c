//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    int i, j, k, l, m, n;

    printf("Enter your text: ");
    gets(text);

    // Find the length of the text
    n = strlen(text);

    // Create a 2D array to store the ASCII art
    char art[n][n];

    // Initialize the array with spaces
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            art[i][j] = ' ';
        }
    }

    // Create the ASCII art
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            // If the current character is a letter or a number, draw a heart
            if (isalpha(text[i]) || isdigit(text[i]))
            {
                art[i][j] = '*';
            }
            // If the current character is a space, draw a space
            else if (text[i] == ' ')
            {
                art[i][j] = ' ';
            }
            // If the current character is a special character, draw a line
            else
            {
                art[i][j] = '-';
            }
        }
    }

    // Print the ASCII art
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}