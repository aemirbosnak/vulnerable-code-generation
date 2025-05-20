//FormAI DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given character is an operator or not
int isOperator(char c) {
    char operators[] = "+-*/%";
    for (int i = 0; i < strlen(operators); i++) {
        if (operators[i] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a given string is a valid number or not
int isNumber(char num[]) {
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] < '0' || num[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Function to parse the given expression and print the tokens
void parseExpression(char expr[]) {
    int len = strlen(expr);
    char token[20];
    int tokenIndex = 0;
    for (int i = 0; i < len; i++) {
        if (expr[i] == ' ') {
            continue;
        }
        if (isOperator(expr[i])) {
            token[tokenIndex] = '\0';
            if (tokenIndex > 0) {
                printf("%s\n", token);
                tokenIndex = 0;
            }
            printf("%c\n", expr[i]);
        } else {
            token[tokenIndex] = expr[i];
            tokenIndex++;
        }
    }
    if (tokenIndex > 0) {
        token[tokenIndex] = '\0';
        if (isNumber(token)) {
            printf("%s\n", token);
        }
    }
}

// Main function
int main() {
    char expr[100];
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    printf("Tokens are:\n");
    parseExpression(expr);
    return 0;
}