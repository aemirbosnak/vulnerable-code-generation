//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is valid in the alien language
int isValidChar(char c)
{
    char validChars[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int i, valid = 0;
    c = toupper(c);
    for(i = 0; i < 6; i++)
    {
        if(c == validChars[i])
        {
            valid = 1;
            break;
        }
    }
    return valid;
}

// Function to translate the alien language string
void translate(char *string)
{
    int i;
    for(i = 0; i < strlen(string); i++)
    {
        if(isValidChar(string[i]))
        {
            if(string[i] == 'A')
            {
                printf("Hello ");
            }
            else if(string[i] == 'B')
            {
                printf("How ");
            }
            else if(string[i] == 'C')
            {
                printf("Are ");
            }
            else if(string[i] == 'D')
            {
                printf("You ");
            }
            else if(string[i] == 'E')
            {
                printf("Today?");
            }
            else if(string[i] == 'F')
            {
                printf("\n");
            }
        }
        else
        {
            printf("%c", string[i]);
        }
    }
}

int main()
{
    char string[100];
    printf("Enter an alien language string: ");
    fgets(string, 100, stdin);

    // Remove newline character at the end of the string
    if(string[strlen(string)-1] == '\n')
    {
        string[strlen(string)-1] = '\0';
    }

    translate(string);
    return 0;
}