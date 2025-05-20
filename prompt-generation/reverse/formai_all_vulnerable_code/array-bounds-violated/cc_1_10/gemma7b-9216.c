//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int history[100];
    int historyIndex;
} Calculator;

Calculator calculator;

void clearCalculator() {
    calculator.position = 0;
    calculator.historyIndex = 0;
    calculator.buffer[0] = '\0';
}

void addToBuffer(char character) {
    if (calculator.position >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calculator.buffer[calculator.position++] = character;
}

void calculate() {
    char operator = calculator.buffer[calculator.position - 1];
    int operand1 = atoi(calculator.buffer);
    int operand2 = atoi(calculator.buffer + calculator.position);

    switch (operator) {
        case '+':
            calculator.history[calculator.historyIndex++] = operand1 + operand2;
            break;
        case '-':
            calculator.history[calculator.historyIndex++] = operand1 - operand2;
            break;
        case '*':
            calculator.history[calculator.historyIndex++] = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                return;
            }
            calculator.history[calculator.historyIndex++] = operand1 / operand2;
            break;
        default:
            return;
    }

    clearCalculator();
    addToBuffer(calculator.history[calculator.historyIndex - 1]);
}

int main() {
    char input;

    clearCalculator();

    printf("Enter an expression: ");

    // Loop to read input until the user enters an operator or equals sign
    while ((input = getchar()) != '+' && input != '-' && input != '*' && input != '/' && input != '=') {
        addToBuffer(input);
    }

    // Calculate the expression
    calculate();

    // Print the result
    printf("The result is: %d\n", calculator.history[calculator.historyIndex - 1]);

    return 0;
}