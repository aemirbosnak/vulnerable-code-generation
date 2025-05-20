//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
    char operator;
} Calculator;

void initCalculator(Calculator *calc) {
    calc->pos = 0;
    calc->historyPos = 0;
    calc->operator = '\0';
}

void addToBuffer(Calculator *calc, char ch) {
    if (calc->pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[calc->pos++] = ch;
}

void clearBuffer(Calculator *calc) {
    calc->pos = 0;
    calc->operator = '\0';
}

void storeHistory(Calculator *calc, char result) {
    if (calc->historyPos >= 10) {
        return;
    }
    calc->history[calc->historyPos++] = result;
}

double calculate(Calculator *calc) {
    char operator = calc->operator;
    double result = 0.0;
    double num1 = 0.0;
    double num2 = 0.0;

    switch (operator) {
        case '+':
            num1 = atof(calc->buffer);
            num2 = atof(calc->buffer + calc->pos - 1);
            result = num1 + num2;
            break;
        case '-':
            num1 = atof(calc->buffer);
            num2 = atof(calc->buffer + calc->pos - 1);
            result = num1 - num2;
            break;
        case '*':
            num1 = atof(calc->buffer);
            num2 = atof(calc->buffer + calc->pos - 1);
            result = num1 * num2;
            break;
        case '/':
            num1 = atof(calc->buffer);
            num2 = atof(calc->buffer + calc->pos - 1);
            result = num1 / num2;
            break;
        default:
            return -1.0;
    }

    storeHistory(calc, result);

    return result;
}

int main() {
    Calculator calc;
    initCalculator(&calc);

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        addToBuffer(&calc, input[i]);
    }

    char result = calculate(&calc);

    if (result != -1.0) {
        printf("Result: %.2lf\n", result);
    } else {
        printf("Error: Invalid expression.\n");
    }

    return 0;
}