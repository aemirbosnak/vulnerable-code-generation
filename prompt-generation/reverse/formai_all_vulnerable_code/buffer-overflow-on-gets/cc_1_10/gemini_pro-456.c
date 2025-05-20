//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 100

int main()
{
    char input[MAX_INPUT];
    int i;

    printf("Enter a string: ");
    gets(input);

    // Convert all characters to lowercase
    for (i = 0; input[i] != '\0'; i++)
    {
        input[i] = tolower(input[i]);
    }

    // Check for invalid characters
    for (i = 0; input[i] != '\0'; i++)
    {
        if (!isalnum(input[i]) && input[i] != ' ')
        {
            printf("Invalid character: '%c'\n", input[i]);
            return 1;
        }
    }

    // Check for empty string
    if (strlen(input) == 0)
    {
        printf("Empty string\n");
        return 1;
    }

    // Check for duplicate spaces
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ' && input[i+1] == ' ')
        {
            printf("Duplicate spaces\n");
            return 1;
        }
    }

    // Validate the string
    printf("Sanitized string: %s\n", input);
    return 0;
}