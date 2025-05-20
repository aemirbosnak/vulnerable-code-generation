//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to evaluate two numbers based on the operator
int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            printf("Oh no! Division by zero!\n");
            exit(1);
        default: return 0;
    }
}

// Main parsing and evaluation function
int parse_expression(char *expression) {
    int stack[50];
    int top = -1;
    char op = ' ';
    int num = 0;
    int i = 0;
    int current_buffer = 0;

    while (expression[i] != '\0') {
        // If it's a digit, create the number
        if (isdigit(expression[i])) {
            num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            stack[++top] = num; 
        }
        
        // If there's an operator
        if (is_operator(expression[i])) { 
            if (top < 1) {
                printf("Oops! Not enough numbers to process the operator '%c'!\n", expression[i]);
                return 0; 
            }
            op = expression[i];
            int b = stack[top--]; 
            int a = stack[top--]; 
            int result = calculate(a, b, op);
            printf("Calculating: %d %c %d = %d\n", a, op, b, result);
            stack[++top] = result; 
        }
        i++;
    }
    
    return stack[top]; 
}

int main() {
    printf("🎉 Welcome to the Happy Expression Parser! 🎉\n");
    printf("Please enter a simple arithmetic expression (e.g., 3 + 5 * 2): \n");

    char expression[MAX_EXPRESSION_LENGTH];
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);

    // Remove the newline character if it's there
    size_t length = strlen(expression);
    if (length > 0 && expression[length - 1] == '\n') {
        expression[length - 1] = '\0';
    }
    
    int result = parse_expression(expression);
    
    printf("🎈 The result of your happy expression is: %d 🎈\n", result);
    printf("Thank you for using the Happy Expression Parser! 🎊\n");

    return 0;
}