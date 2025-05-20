//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to evaluate a postfix expression
double evaluatePostfix(char *postfix) {
    // Create a stack to store the operands
    double stack[100];
    int top = -1;

    // Iterate over the postfix expression
    for (int i = 0; i < strlen(postfix); i++) {
        // If the character is an operand, push it onto the stack
        if (!isOperator(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        } else {
            // If the character is an operator, pop the top two operands from the stack, perform the operation, and push the result back onto the stack
            double operand1 = stack[top--];
            double operand2 = stack[top--];
            switch (postfix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                case '^':
                    stack[++top] = pow(operand1, operand2);
                    break;
            }
        }
    }

    // Return the top of the stack, which contains the result of the expression
    return stack[top];
}

// Function to convert an infix expression to postfix notation
char *infixToPostfix(char *infix) {
    // Create a stack to store the operators
    char stack[100];
    int top = -1;

    // Create a string to store the postfix expression
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0, j = 0;

    // Iterate over the infix expression
    while (infix[i] != '\0') {
        // If the character is an operand, add it to the postfix expression
        if (!isOperator(infix[i])) {
            postfix[j++] = infix[i];
        } else {
            // If the character is an operator, push it onto the stack
            while (top != -1 && getPrecedence(infix[i]) <= getPrecedence(stack[top])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    // Pop the remaining operators from the stack and add them to the postfix expression
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';

    // Return the postfix expression
    return postfix;
}

// Main function
int main() {
    // Get the infix expression from the user
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert the infix expression to postfix notation
    char *postfix = infixToPostfix(infix);

    // Evaluate the postfix expression
    double result = evaluatePostfix(postfix);

    // Print the result
    printf("The result is: %f\n", result);

    return 0;
}