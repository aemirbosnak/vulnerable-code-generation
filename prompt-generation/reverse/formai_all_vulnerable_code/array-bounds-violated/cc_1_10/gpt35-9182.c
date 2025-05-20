//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>

int main()
{
    // Initializing variables
    char text[100];
    char ascii_art[7][30];
    int i, j, len;

    // Taking input from user
    printf("Enter the text you want to convert: ");
    fgets(text, 100, stdin);

    // Removing the newline character from the end of the input string
    len = strlen(text);
    if(text[len-1] == '\n')
        text[len-1] = '\0';

    // Converting each character of the input text to ASCII art
    for(i=0; i<7; i++)
    {
        for(j=0; j<len; j++)
        {
            switch(text[j])
            {
                case 'A':
                    ascii_art[i][j] = 65+i;
                    break;
                case 'B':
                    ascii_art[i][j] = 66+i;
                    break;
                case 'C':
                    ascii_art[i][j] = 67+i;
                    break;
                // more cases can be added as per requirement
                default:
                    ascii_art[i][j] = ' ';
                    break;
            }
        }
        ascii_art[i][j] = '\0';
    }

    // Printing the ASCII art
    for(i=0; i<7; i++)
    {
        printf("%s\n", ascii_art[i]);
    }

    return 0;
}