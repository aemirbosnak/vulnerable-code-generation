//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

Calculator calc;

void initializeCalculator() {
    calc.pos = 0;
    calc.historyPos = 0;
    memset(calc.buffer, 0, MAX_BUFFER_SIZE);
}

void addToBuffer(char c) {
    if (calc.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc.buffer[calc.pos++] = c;
}

void clearBuffer() {
    calc.pos = 0;
    memset(calc.buffer, 0, MAX_BUFFER_SIZE);
}

void addToHistory(char operation) {
    if (calc.historyPos >= 10) {
        return;
    }
    calc.history[calc.historyPos++] = operation;
}

void calculate() {
    char operation = calc.buffer[0];
    double result = 0;
    double number = 0;

    switch (operation) {
        case '+':
            number = atof(calc.buffer + 1);
            result = number;
            break;
        case '-':
            number = atof(calc.buffer + 1);
            result = -number;
            break;
        case '*':
            number = atof(calc.buffer + 1);
            result = number * number;
            break;
        case '/':
            number = atof(calc.buffer + 1);
            result = number / number;
            break;
        default:
            return;
    }

    addToHistory(operation);
    clearBuffer();
    printf("%f\n", result);
}

int main() {
    initializeCalculator();

    char input;
    while (1) {
        printf("Enter an operation (+, -, *, /, =): ");
        scanf("%c", &input);

        switch (input) {
            case '=':
                calculate();
                break;
            case 'c':
                clearBuffer();
                break;
            default:
                addToBuffer(input);
                break;
        }
    }

    return 0;
}