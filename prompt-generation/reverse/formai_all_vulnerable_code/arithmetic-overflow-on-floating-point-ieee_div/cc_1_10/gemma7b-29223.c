//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int top;
    char operator;
} Calculator;

void initCalculator(Calculator *calc) {
    calc->pos = 0;
    calc->top = -1;
    calc->operator = '\0';
}

void addToBuffer(Calculator *calc, char num) {
    if (calc->top == MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->pos] = num;
}

void setOperator(Calculator *calc, char op) {
    calc->operator = op;
}

double calculateResult(Calculator *calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = atof(calc->buffer[0]) + atof(calc->buffer[1]);
            break;
        case '-':
            result = atof(calc->buffer[0]) - atof(calc->buffer[1]);
            break;
        case '*':
            result = atof(calc->buffer[0]) * atof(calc->buffer[1]);
            break;
        case '/':
            result = atof(calc->buffer[0]) / atof(calc->buffer[1]);
            break;
        default:
            return -1.0;
    }
    return result;
}

int main() {
    Calculator calc;
    initCalculator(&calc);

    addToBuffer(&calc, '5');
    addToBuffer(&calc, '2');
    setOperator(&calc, '+');
    addToBuffer(&calc, '3');
    addToBuffer(&calc, '4');
    setOperator(&calc, '-');
    addToBuffer(&calc, '6');
    addToBuffer(&calc, '8');
    setOperator(&calc, '*');
    addToBuffer(&calc, '9');
    addToBuffer(&calc, '2');
    setOperator(&calc, '/');
    addToBuffer(&calc, '1');
    addToBuffer(&calc, '4');

    double result = calculateResult(&calc);

    if (result != -1.0) {
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Error: Invalid operator.\n");
    }

    return 0;
}