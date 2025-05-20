//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

Calculator calculator;

void initializeCalculator() {
    calculator.pos = 0;
    calculator.historyPos = 0;
    calculator.history[0] = 0;
    for (int i = 1; i < 10; i++) {
        calculator.history[i] = -1;
    }
}

void addToCalculator(char ch) {
    if (calculator.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calculator.buffer[calculator.pos++] = ch;
}

void clearCalculator() {
    calculator.pos = 0;
}

void calculate() {
    char operator = calculator.buffer[0];
    double num1 = atof(calculator.buffer + 1);
    double num2 = atof(calculator.buffer + calculator.pos);

    double result = 0;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }

    addToCalculator(result);
    clearCalculator();
}

int main() {
    initializeCalculator();

    char input;
    printf("Enter an expression: ");
    scanf("%c", &input);

    switch (input) {
        case 'c':
            clearCalculator();
            break;
        case '=':
            calculate();
            break;
        default:
            addToCalculator(input);
    }

    return 0;
}