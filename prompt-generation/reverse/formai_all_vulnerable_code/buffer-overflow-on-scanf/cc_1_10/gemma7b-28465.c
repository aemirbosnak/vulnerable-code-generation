//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
    double operand;
    char operator;
} Calculator;

Calculator calc;

void clear_calculator(void) {
    calc.pos = 0;
    calc.result = 0.0;
    calc.operand = 0.0;
    calc.operator = '\0';
}

void append_number(double number) {
    if (calc.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc.buffer[calc.pos++] = (number - (int)number) * 10 + (int)number + '0';
}

void append_operator(char operator) {
    calc.operator = operator;
}

void calculate(void) {
    switch (calc.operator) {
        case '+':
            calc.result = calc.operand + calc.result;
            break;
        case '-':
            calc.result = calc.operand - calc.result;
            break;
        case '*':
            calc.result = calc.operand * calc.result;
            break;
        case '/':
            if (calc.operand == 0) {
                printf("Cannot divide by zero.\n");
                return;
            }
            calc.result = calc.operand / calc.result;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }
    calc.operand = calc.result;
}

int main(void) {
    char input[MAX_BUFFER_SIZE];

    clear_calculator();

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                append_number((double)input[i] - '0');
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                append_operator(input[i]);
                break;
            default:
                break;
        }
    }

    calculate();

    printf("The result is: %.2lf\n", calc.result);

    return 0;
}