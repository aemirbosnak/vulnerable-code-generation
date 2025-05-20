//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int state;
    double result;
} Calculator;

void initializeCalculator(Calculator *calc) {
    calc->position = 0;
    calc->state = 0;
    calc->result = 0.0;
    calc->buffer[0] = '\0';
}

void calculate(Calculator *calc) {
    double operand1 = atof(calc->buffer);
    double operand2 = atof(calc->buffer + calc->position);
    double operator = atof(calc->buffer + calc->position + 1);

    switch (calc->state) {
        case 0:
            calc->result = operand1 + operand2 * operator;
            break;
        case 1:
            calc->result = operand1 - operand2 * operator;
            break;
        case 2:
            calc->result = operand1 * operand2 * operator;
            break;
        case 3:
            calc->result = operand1 / operand2 * operator;
            break;
    }

    calc->position = calc->position + 2;
    calc->buffer[calc->position] = '\0';
}

int main() {
    Calculator calc;
    initializeCalculator(&calc);

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    char *p = input;
    while (*p) {
        if (*p >= '0' && *p <= '9') {
            calc.buffer[calc.position++] = *p;
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            calc.state = *p - '0';
            calculate(&calc);
        } else if (*p == '=') {
            printf("The result is: %.2lf\n", calc.result);
            initializeCalculator(&calc);
        }
        p++;
    }

    return 0;
}