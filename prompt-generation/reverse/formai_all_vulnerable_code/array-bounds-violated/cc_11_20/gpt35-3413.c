//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_HEIGHT 20
#define MAX_WIDTH 60

char ascii_art[MAX_HEIGHT][MAX_WIDTH+1];

int main()
{
    char text[MAX_WIDTH+1];
    int i, j, k;

    printf("Enter text to be converted to ASCII art (max %d characters):\n", MAX_WIDTH);
    fgets(text, MAX_WIDTH+1, stdin);

    // Remove newline character from input
    for (i = 0; text[i]; i++)
    {
        if (text[i] == '\n')
        {
            text[i] = '\0';
            break;
        }
    }

    // Convert text to uppercase
    for (i = 0; text[i]; i++)
    {
        text[i] = toupper(text[i]);
    }

    // Generate ASCII art
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        for (j = 0, k = 0; k < MAX_WIDTH && text[j]; j++, k += 4)
        {
            switch (text[j])
            {
                case 'A':
                    ascii_art[i][k+1] = '/';
                    ascii_art[i][k+2] = '\\';
                    ascii_art[i-1][k+2] = '_';
                    ascii_art[i][k] = ascii_art[i][k+3] = '_';
                    break;
                case 'B':
                    ascii_art[i][k] = ascii_art[i][k+3] = '_';
                    ascii_art[i][k+1] = ascii_art[i][k+2] = '|';
                    ascii_art[i-1][k] = ascii_art[i-1][k+3] = '|';
                    ascii_art[i][k+1] = ascii_art[i][k+2] = '_';
                    break;
                case 'C':
                    ascii_art[i][k+1] = ascii_art[i][k+2] = '_';
                    ascii_art[i][k] = ascii_art[i-1][k+2] = '/';
                    ascii_art[i][k+3] = ascii_art[i-1][k+1] = '\\';
                    break;
                // Continue for the rest of the alphabet
                default:
                    break;
            }
        }
    }

    // Print ASCII art
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        for (j = 0; j < MAX_WIDTH; j++)
        {
            printf("%c", ascii_art[i][j] ? ascii_art[i][j] : ' ');
        }
        printf("\n");
    }

    return 0;
}