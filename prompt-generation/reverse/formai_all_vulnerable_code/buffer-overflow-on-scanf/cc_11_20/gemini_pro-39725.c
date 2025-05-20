//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is our very own C Syntax parsing engine!
int main()
{
    // Let's get the user's input.
    printf("Enter a C expression: ");
    char input[1024];
    scanf("%s", input);

    // Now, let's break the input into tokens.
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        // Check if the token is a keyword.
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "double") == 0 || strcmp(token, "char") == 0)
        {
            printf("%s is a keyword.\n", token);
        }
        // Check if the token is an identifier.
        else if (token[0] >= 'a' && token[0] <= 'z')
        {
            printf("%s is an identifier.\n", token);
        }
        // Check if the token is a constant.
        else if (token[0] >= '0' && token[0] <= '9')
        {
            printf("%s is a constant.\n", token);
        }
        // Check if the token is an operator.
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
        {
            printf("%s is an operator.\n", token);
        }
        // Check if the token is a delimiter.
        else if (strcmp(token, ";") == 0 || strcmp(token, ",") == 0 || strcmp(token, "(") == 0 || strcmp(token, ")") == 0)
        {
            printf("%s is a delimiter.\n", token);
        }
        // Check if the token is an unknown character.
        else
        {
            printf("%s is an unknown character.\n", token);
        }

        // Get the next token.
        token = strtok(NULL, " ");
    }

    return 0;
}