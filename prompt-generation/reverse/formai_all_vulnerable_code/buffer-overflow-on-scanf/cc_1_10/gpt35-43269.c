//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHARS 80
#define MAX_LINES 20
#define LETTERS 26

// ASCII art arrays for each letter
char A[MAX_LINES][MAX_CHARS] =
    {"  /\\  ",
     " /  \\ ",
     "/    \\",
     "|------|",
     "|      |",
     "|      |",
     "|      |"};

char B[MAX_LINES][MAX_CHARS] =
    {"|------/",
     "|     / ",
     "|----/  ",
     "|   \\   ",
     "|    \\  ",
     "|     \\ ",
     "|------\\"};

// add more letters here...

// function to print ASCII art of a letter
void printLetter(char letter[MAX_LINES][MAX_CHARS], int scale)
{
    for (int i = 0; i < MAX_LINES; i++)
    {
        for (int k = 0; k < scale; k++) // scale vertically
        {
            for (int j = 0; j < MAX_CHARS; j++)
            {
                for (int l = 0; l < scale; l++) // scale horizontally
                {
                    if (letter[i][j] == '/')
                    {
                        for (int s = 0; s < scale - l; s++)
                            putchar(' ');
                        putchar('/');
                        break;
                    }
                    else if (letter[i][j] == '\\')
                    {
                        putchar('\\');
                        for (int s = 0; s < scale - l - 1; s++)
                            putchar(' ');
                        break;
                    }
                    else
                    {
                        putchar(letter[i][j]);
                    }
                }
            }
            putchar('\n');
        }
    }
}

int main()
{
    char input;
    int scale;

    // get input from user
    printf("Enter a letter (A-Z): ");
    scanf(" %c", &input);
    printf("Enter a scale factor (1-10): ");
    scanf("%d", &scale);
    scale = (scale < 1) ? 1 : scale; // enforce minimum scale factor
    scale = (scale > 10) ? 10 : scale; // enforce maximum scale factor

    // convert input to uppercase
    input = toupper(input);
    if (input < 'A' || input > 'Z')
    {
        printf("Invalid input\n");
        exit(1);
    }

    // print ASCII art of input letter
    switch (input)
    {
    case 'A':
        printLetter(A, scale);
        break;
    case 'B':
        printLetter(B, scale);
        break;
    // add more cases here...
    default:
        printf("Letter not found\n");
        break;
    }

    return 0;
}