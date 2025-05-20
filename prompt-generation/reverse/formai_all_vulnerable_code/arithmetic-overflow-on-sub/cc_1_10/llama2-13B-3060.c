//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 10
#define MAX_EXPRESSIONS 5

// Function prototypes
int eval(char *expression);
void parse_expression(char *expression, int *operands, int *expressions);

int main() {
    char user_input[100];
    int operands[MAX_OPERANDS];
    int expressions[MAX_EXPRESSIONS];
    int i, j;

    // Retro-style prompt
    printf("Welcome to the Arithmetic Machine!\n");
    printf("Enter an expression (e.g. 2+3*4): ");

    // Read user input
    fgets(user_input, 100, stdin);

    // Parse the expression
    parse_expression(user_input, operands, expressions);

    // Evaluate the expression
    int result = eval(user_input);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}

// Parse an expression
void parse_expression(char *expression, int *operands, int *expressions) {
    char op;
    int i, j;

    // Tokenize the expression
    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Save the current operand and operator
            operands[j] = expression[i - 1];
            expressions[j] = expression[i];

            // Increment the operand and expression indices
            j++;
        }
    }

    // Check for errors
    if (j == MAX_OPERANDS || j == MAX_EXPRESSIONS) {
        printf("Error: Too many operands or expressions\n");
        return;
    }
}

// Evaluate an expression
int eval(char *expression) {
    int operands[MAX_OPERANDS];
    int expressions[MAX_EXPRESSIONS];
    int i, j;

    // Tokenize the expression
    parse_expression(expression, operands, expressions);

    // Evaluate the expression
    int result = 0;
    for (i = 0; i < j; i++) {
        switch (expressions[i]) {
            case '+':
                result += operands[i];
                break;
            case '-':
                result -= operands[i];
                break;
            case '*':
                result *= operands[i];
                break;
            case '/':
                result /= operands[i];
                break;
            default:
                printf("Error: Unknown operator %c\n", expressions[i]);
                return 0;
        }
    }

    return result;
}