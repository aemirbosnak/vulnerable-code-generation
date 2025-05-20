//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1024];
    int i = 0;

    printf("Enter a message: ");
    fgets(input, 1024, stdin);

    // Strip all vowels and punctuation from the input
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = ' ';
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = ' ';
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            input[i] = ' ';
        }
        else if (input[i] == '.' || input[i] == ',' || input[i] == '!' || input[i] == '?')
        {
            input[i] = ' ';
        }
    }

    // Remove all consecutive spaces
    i = 0;
    for (char *p = input; *p != '\0'; p++)
    {
        if (*p == ' ' && *(p-1) == ' ')
        {
            *p = '\0';
        }
        else
        {
            input[i++] = *p;
        }
    }

    // Print the sanitized message
    printf("Sanitized message: %s\n", input);

    return 0;
}