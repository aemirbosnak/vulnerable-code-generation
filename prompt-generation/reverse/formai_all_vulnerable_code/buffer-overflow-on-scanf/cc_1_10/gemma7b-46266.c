//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 10

void parse_expression(char **tokens, int index);

int main()
{
    char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    int index = 0;

    printf("Enter an expression: ");
    scanf("%s", tokens[index]);

    parse_expression(tokens, index);

    printf("Expression parsed successfully.\n");

    return 0;
}

void parse_expression(char **tokens, int index)
{
    char *token = tokens[index];

    if (token == NULL)
    {
        return;
    }

    switch (token[0])
    {
        case '(':
            index++;
            parse_expression(tokens, index);
            break;
        case ')':
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            index++;
            parse_expression(tokens, index);
            break;
        default:
            printf("Syntax error.\n");
            exit(1);
    }
}