//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
    char operator;
} Calculator;

void calculator_init(Calculator *calc) {
    calc->pos = 0;
    calc->historyPos = 0;
    calc->operator = '\0';
}

void calculator_add(Calculator *calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->operator = '+';
}

void calculator_sub(Calculator *calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->operator = '-';
}

void calculator_mul(Calculator *calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->operator = '*';
}

void calculator_div(Calculator *calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->operator = '/';
}

void calculator_equals(Calculator *calc) {
    calc->history[calc->historyPos++] = atoi(calc->buffer);
    printf("%d\n", calc->history[calc->historyPos - 1]);
}

int main() {
    Calculator calc;
    calculator_init(&calc);

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '+':
                calculator_add(&calc, input[i - 1] - '0');
                break;
            case '-':
                calculator_sub(&calc, input[i - 1] - '0');
                break;
            case '*':
                calculator_mul(&calc, input[i - 1] - '0');
                break;
            case '/':
                calculator_div(&calc, input[i - 1] - '0');
                break;
            case '=':
                calculator_equals(&calc);
                break;
            default:
                calculator_add(&calc, input[i] - '0');
                break;
        }
    }

    return 0;
}