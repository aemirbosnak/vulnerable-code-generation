//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int history[10];
    int history_position;
} Calculator;

Calculator calculator;

void calculate(char operator, int operand) {
    switch (operator) {
        case '+':
            calculator.buffer[calculator.position++] = '+';
            calculator.buffer[calculator.position++] = operand;
            break;
        case '-':
            calculator.buffer[calculator.position++] = '-';
            calculator.buffer[calculator.position++] = operand;
            break;
        case '*':
            calculator.buffer[calculator.position++] = '*';
            calculator.buffer[calculator.position++] = operand;
            break;
        case '/':
            calculator.buffer[calculator.position++] = '/';
            calculator.buffer[calculator.position++] = operand;
            break;
        default:
            break;
    }
}

void store_history(char operator, int operand) {
    calculator.history[calculator.history_position++] = operator;
    calculator.history[calculator.history_position++] = operand;
}

void clear_history() {
    calculator.history_position = 0;
}

int main() {
    char input[MAX_BUFFER_SIZE];
    int i = 0;

    calculator.position = 0;
    calculator.history_position = 0;

    printf("Enter an expression: ");

    // Get the input expression
    while (input[i] = getchar() != '\n') {
        i++;
    }

    // Calculate the expression
    for (i = 0; input[i] != '\0'; i++) {
        char operator = input[i];
        int operand = input[i + 1] - '0';

        calculate(operator, operand);
        store_history(operator, operand);
    }

    // Print the result
    printf("Result: %s\n", calculator.buffer);

    // Clear the history
    clear_history();

    return 0;
}