//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform a mathematical operation
double calculate(double num1, double num2, char op)
{
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        case '%':
            return (int) num1 % (int) num2;
        case '^':
            return pow(num1, num2);
        default:
            printf("Invalid operator\n");
            return 0;
    }
}

// Function to get a mathematical expression from the user
char* get_expression()
{
    char* expression = malloc(sizeof(char) * 100);
    printf("Enter a mathematical expression: ");
    scanf("%s", expression);
    return expression;
}

// Function to tokenize the expression
char** tokenize_expression(char* expression)
{
    char** tokens = malloc(sizeof(char*) * 100);
    int num_tokens = 0;
    char* token = strtok(expression, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

// Function to evaluate the expression
double evaluate_expression(char** tokens)
{
    double stack[100];
    int top = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
            // Operand
            stack[top++] = atof(tokens[i]);
        } else {
            // Operator
            double num2 = stack[--top];
            double num1 = stack[--top];
            double result = calculate(num1, num2, tokens[i][0]);
            stack[top++] = result;
        }
    }
    return stack[top - 1];
}

// Main function
int main()
{
    char* expression = get_expression();
    char** tokens = tokenize_expression(expression);
    double result = evaluate_expression(tokens);
    printf("Result: %f\n", result);
    return 0;
}