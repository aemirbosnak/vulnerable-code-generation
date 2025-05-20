//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>

void printChar(char character, int n);

int main()
{
    char input[1000];
    int length = 0;
    
    // get input from user
    printf("Enter text to convert into ASCII art:\n");
    fgets(input, 1000, stdin);
    
    // find length of input
    while (input[length] != '\0')
    {
        length++;
    }
    
    // remove new line character
    input[length - 1] = '\0';
    length--;
    
    // print ASCII art
    for (int i = 0; i < length; i++)
    {
        if (input[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            switch (input[i])
            {
                case 'a':
                case 'A':
                    printChar(' ', 2);
                    printChar('_', 1);
                    printChar('_', 1);
                    printChar(' ', 2);
                    break;
                case 'b':
                case 'B':
                    printChar('|', 1);
                    printChar('_', 1);
                    printChar('_', 1);
                    printChar('|', 1);
                    break;
                case 'c':
                case 'C':
                    printChar(' ', 1);
                    printChar('_', 1);
                    printChar('_', 1);
                    printChar('|', 1);
                    break;
                // continue with the rest of the alphabet
                default:
                    printf("Character not recognized.");
            }
        }
    }
    
    return 0;
}

void printChar(char character, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", character);
    }
}