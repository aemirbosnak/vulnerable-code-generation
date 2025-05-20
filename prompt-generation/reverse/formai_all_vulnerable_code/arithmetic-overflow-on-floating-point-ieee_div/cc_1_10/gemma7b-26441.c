//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    float result;
} Calculator;

Calculator* calculator_init(void) {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->top = -1;
    calc->result = 0.0f;
    return calc;
}

void calculator_push(Calculator* calc, char number) {
    if (calc->top >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[++calc->top] = number;
}

void calculator_pop(Calculator* calc) {
    if (calc->top == -1) {
        return;
    }
    calc->top--;
}

void calculator_operator(Calculator* calc, char operator) {
    switch (operator) {
        case '+':
            calculator_push(calc, '+');
            break;
        case '-':
            calculator_push(calc, '-');
            break;
        case '*':
            calculator_push(calc, '*');
            break;
        case '/':
            calculator_push(calc, '/');
            break;
        default:
            return;
    }
}

float calculator_calculate(Calculator* calc) {
    float result = 0.0f;
    char operator = calc->buffer[0];
    switch (operator) {
        case '+':
            result = (float)calc->buffer[1] + calc->result;
            break;
        case '-':
            result = (float)calc->buffer[1] - calc->result;
            break;
        case '*':
            result = (float)calc->buffer[1] * calc->result;
            break;
        case '/':
            result = (float)calc->buffer[1] / calc->result;
            break;
        default:
            return -1.0f;
    }
    calc->result = result;
    return result;
}

int main() {
    Calculator* calc = calculator_init();

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
                calculator_push(calc, input[i]);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                calculator_operator(calc, input[i]);
                break;
            default:
                break;
        }
    }

    float result = calculator_calculate(calc);

    if (result != -1.0f) {
        printf("The result is: %.2f\n", result);
    } else {
        printf("Error: Invalid expression.\n");
    }

    free(calc);

    return 0;
}