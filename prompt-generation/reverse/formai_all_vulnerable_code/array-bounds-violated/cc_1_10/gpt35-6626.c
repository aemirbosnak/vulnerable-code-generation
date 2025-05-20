//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

// Helper function to tokenize input string
int tokenize_input_string(char *input_string, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH])
{
    char *token = strtok(input_string, " "); // initialize strtok() with the first argument

    int num_tokens = 0;
    while (token != NULL)
    {
        strcpy(tokens[num_tokens], token); // copy the token into the tokens array
        num_tokens++;

        if (num_tokens > MAX_TOKENS) // check if too many tokens
        {
            printf("Error: too many tokens\n");
            exit(1);
        }

        token = strtok(NULL, " "); // get the next token
    }

    return num_tokens;
}

int main(void)
{
    char input_string[MAX_TOKEN_LENGTH];
    printf("Enter a C syntax statement: ");
    fgets(input_string, MAX_TOKEN_LENGTH, stdin);

    // Remove newline character from input string
    int len = strlen(input_string);
    if (input_string[len - 1] == '\n') {
        input_string[len - 1] = '\0';
    }

    // Tokenize the input string
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int num_tokens = tokenize_input_string(input_string, tokens);

    // Check for valid C syntax statement
    if (num_tokens < 2)
    {
        printf("Error: not a valid C syntax statement\n");
        exit(1);
    }

    // Check for a valid variable declaration statement
    if (strcmp(tokens[num_tokens-2], "int") != 0 || tokens[num_tokens-1][strlen(tokens[num_tokens-1])-1] != ';')
    {
        printf("Error: not a valid variable declaration statement\n");
        exit(1);
    }

    printf("Valid C syntax statement: %s\n", input_string);

    return 0;
}