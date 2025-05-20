//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to parse an arithmetic expression
int parse_expression(char *expression) {
    // Declare the variables to store the expression tokens
    int token_type = 0;
    char token_str[100];
    char *token_ptr = token_str;

    // Loop over the characters in the expression
    while (*expression) {
        // Get the next character and check if it is a valid token
        if (isspace(*expression)) {
            // If the character is whitespace, skip it
            expression++;
            continue;
        } else if (*expression == '(') {
            // If the character is an open parenthesis, push it onto the stack
            expression++;
            continue;
        } else if (*expression == ')') {
            // If the character is a close parenthesis, pop the top of the stack
            if (token_ptr!= token_str) {
                // If there is a token on the stack, pop it and return its type
                token_type = atoi(token_ptr);
                expression = token_ptr;
                token_ptr = token_str;
                continue;
            } else {
                // If there are no tokens on the stack, return -1
                return -1;
            }
        } else if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/') {
            // If the character is an arithmetic operator, push it onto the stack
            strcpy(token_ptr, expression);
            expression++;
            continue;
        } else {
            // If the character is not a valid token, return -1
            return -1;
        }
    }

    // If there are no valid tokens, return -1
    if (token_ptr!= token_str) {
        return -1;
    }

    // If there are tokens on the stack, pop them and return their types
    int result = 0;
    while (token_ptr!= token_str) {
        result = result * 10 + atoi(token_ptr);
        token_ptr = token_str;
    }
    return result;
}

int main() {
    // Prompt the user for an arithmetic expression
    printf("Enter an arithmetic expression: ");
    char expression[100];
    scanf("%s", expression);

    // Parse the expression and print the result
    int result = parse_expression(expression);
    if (result!= -1) {
        printf("Result: %d\n", result);
    } else {
        printf("Invalid expression!\n");
    }

    return 0;
}