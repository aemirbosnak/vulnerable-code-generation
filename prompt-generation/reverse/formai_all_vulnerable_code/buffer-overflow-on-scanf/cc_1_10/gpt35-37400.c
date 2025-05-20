//FormAI DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Declaring global variables for parsing
int i = 0;
char input[100];

// Forward declaration of parseStatement function
int parseStatement();

// Function for parsing expressions
int parseExpression() {
    int result = 0;
    
    // Check if first character is a digit
    if (isdigit(input[i])) {
        result = atoi(&input[i]);
    } else if (input[i] == '(') {
        i++;
        result = parseStatement();
        
        if (input[i] != ')') {
            printf("Parse error: Expected ')' but found '%c'\n", input[i]);
            exit(1);
        }
    } else {
        printf("Parse error: Expected number or '(' but found '%c'\n", input[i]);
        exit(1);
    }
    
    // Move to next character
    i++;
    
    return result;
}

// Function for parsing statements
int parseStatement() {
    int result = parseExpression();
    
    while (input[i] == '+' || input[i] == '-') {
        char operator = input[i];
        i++;
        
        int right = parseExpression();
        
        if (operator == '+') {
            result += right;
        } else {
            result -= right;
        }
    }
    
    return result;
}

// Main function
int main() {
    printf("Enter a mathematical expression: ");
    scanf("%s", input);
    
    int result = parseStatement();
    
    printf("Result: %d\n", result);
    
    return 0;
}