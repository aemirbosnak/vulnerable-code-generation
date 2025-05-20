//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    char operator;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->index = 0;
    calc->operator = '\0';
    calc->result = 0.0;
    return calc;
}

void calculator_add(Calculator* calc, char operator, double num) {
    calc->buffer[calc->index++] = operator;
    calc->buffer[calc->index++] = num;
    calc->operator = operator;
    calc->result = 0.0;
}

void calculator_clear(Calculator* calc) {
    calc->index = 0;
    calc->operator = '\0';
    calc->result = 0.0;
}

double calculator_calculate(Calculator* calc) {
    double result = 0.0;
    switch (calc->operator) {
        case '+':
            result = calc->result + (double)calc->buffer[calc->index - 1];
            break;
        case '-':
            result = calc->result - (double)calc->buffer[calc->index - 1];
            break;
        case '*':
            result = calc->result * (double)calc->buffer[calc->index - 1];
            break;
        case '/':
            result = calc->result / (double)calc->buffer[calc->index - 1];
            break;
    }
    calc->result = result;
    return result;
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    char* token = strtok(input, " ");

    while (token) {
        if (strcmp(token, "=") == 0) {
            calculator_calculate(calc);
            printf("Result: %.2lf\n", calc->result);
        } else {
            double num = atof(token);
            calculator_add(calc, token[0], num);
        }

        token = strtok(NULL, " ");
    }

    calculator_clear(calc);
    return 0;
}