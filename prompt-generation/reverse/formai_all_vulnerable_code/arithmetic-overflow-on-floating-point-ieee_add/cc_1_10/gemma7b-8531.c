//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    char operators[4];
    double result;
} Calculator;

Calculator* createCalculator() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->top = -1;
    calculator->operators[0] = '+';
    calculator->operators[1] = '-';
    calculator->operators[2] = '*';
    calculator->operators[3] = '/';
    calculator->result = 0.0;
    return calculator;
}

void addToCalculator(Calculator* calculator, char number) {
    if (calculator->top == MAX_BUFFER_SIZE - 1) {
        printf("Error: Calculator buffer overflow!\n");
        return;
    }
    calculator->buffer[++calculator->top] = number;
}

void calculateResult(Calculator* calculator) {
    double operand1 = 0.0;
    double operand2 = 0.0;
    char operator = calculator->operators[0];

    switch (operator) {
        case '+':
            operand1 = atof(calculator->buffer[0]) + atof(calculator->buffer[1]);
            break;
        case '-':
            operand1 = atof(calculator->buffer[0]) - atof(calculator->buffer[1]);
            break;
        case '*':
            operand1 = atof(calculator->buffer[0]) * atof(calculator->buffer[1]);
            break;
        case '/':
            operand1 = atof(calculator->buffer[0]) / atof(calculator->buffer[1]);
            break;
    }

    calculator->result = operand1;
}

int main() {
    Calculator* calculator = createCalculator();

    // Add numbers and operators to the calculator
    addToCalculator(calculator, '5');
    addToCalculator(calculator, '2');
    addToCalculator(calculator, '+');
    addToCalculator(calculator, '3');
    addToCalculator(calculator, '*');
    addToCalculator(calculator, '4');

    // Calculate the result
    calculateResult(calculator);

    // Print the result
    printf("The result is: %.2lf\n", calculator->result);

    return 0;
}