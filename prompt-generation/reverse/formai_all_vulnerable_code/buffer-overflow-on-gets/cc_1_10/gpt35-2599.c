//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum buffer size
#define MAX_BUFFER_SIZE 512

int main()
{
    // Allocate buffer
    char buffer[MAX_BUFFER_SIZE];

    // Prompt user to enter a C syntax statement
    printf("Please enter a C syntax statement:\n");
    gets(buffer);

    // Perform basic error checking
    if (strlen(buffer) == 0)
    {
        printf("Error: statement cannot be empty.\n");
        return 0;
    }

    // Parse the syntax statement
    int i = 0;
    int length = strlen(buffer);
    int bracket_count = 0;
    int semicolon_count = 0;
    char last_char = '\0';

    while (i < length)
    {
        char current_char = buffer[i++];

        switch (current_char)
        {
            case '{':
                bracket_count++; break;
            case '}':
                bracket_count--; break;
            case ';':
                semicolon_count++; break;
            default:
                break;
        }

        last_char = current_char;
    }

    // Print out the results of parsing
    if (bracket_count != 0)
    {
        printf("Error: missing bracket(s).\n");
    }
    else if (semicolon_count == 0)
    {
        printf("Error: missing semicolon.\n");
    }
    else if (last_char != ';')
    {
        printf("Error: statement must end with semicolon.\n");
    }
    else
    {
        printf("Syntax statement is valid.\n");
    }

    return 0;
}