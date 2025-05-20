//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    double result;
} Calculator;

void calculator_init(Calculator *calc) {
    calc->top = -1;
    calc->result = 0.0;
    calc->buffer[0] = '\0';
}

void calculator_push(Calculator *calc, char digit) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
        return;
    }

    calc->buffer[++calc->top] = digit;
    calc->buffer[calc->top + 1] = '\0';
}

double calculator_pop(Calculator *calc) {
    if (calc->top < 0) {
        return 0.0;
    }

    double result = calc->buffer[calc->top] - '0';
    calc->top--;

    return result;
}

void calculator_operator(Calculator *calc, char operator) {
    switch (operator) {
        case '+':
            calc->result += calculator_pop(calc);
            break;
        case '-':
            calc->result -= calculator_pop(calc);
            break;
        case '*':
            calc->result *= calculator_pop(calc);
            break;
        case '/':
            if (calculator_pop(calc) == 0) {
                return;
            }
            calc->result /= calculator_pop(calc);
            break;
        case '^':
            calc->result = pow(calculator_pop(calc), calculator_pop(calc));
            break;
        default:
            return;
    }

    calculator_push(calc, '.');
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    char input[MAX_BUFFER_SIZE];

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
                calculator_push(&calc, input[i]);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                calculator_operator(&calc, input[i]);
                break;
            default:
                break;
        }
    }

    printf("Result: %.2lf\n", calc.result);

    return 0;
}