//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int hist_pos;
} Calculator;

Calculator calculator;

void init_calculator() {
    calculator.pos = 0;
    calculator.hist_pos = 0;
    memset(calculator.buffer, 0, MAX_BUFFER_SIZE);
}

void append_number(int num) {
    if (calculator.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calculator.buffer[calculator.pos++] = num + '0';
}

void clear_buffer() {
    calculator.pos = 0;
    memset(calculator.buffer, 0, MAX_BUFFER_SIZE);
}

void enter_operator(char op) {
    if (calculator.pos == 0) {
        return;
    }
    calculator.buffer[calculator.pos++] = op;
}

void calculate() {
    int num1, num2;
    char operator;

    if (calculator.pos < 2) {
        return;
    }

    num1 = calculator.buffer[0] - '0';
    num2 = calculator.buffer[1] - '0';
    operator = calculator.buffer[2];

    switch (operator) {
        case '+':
            calculator.history[calculator.hist_pos++] = num1 + num2;
            break;
        case '-':
            calculator.history[calculator.hist_pos++] = num1 - num2;
            break;
        case '*':
            calculator.history[calculator.hist_pos++] = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                return;
            }
            calculator.history[calculator.hist_pos++] = num1 / num2;
            break;
    }

    clear_buffer();
}

int main() {
    init_calculator();

    char input;
    int num;

    printf("Enter an expression: ");

    // Get the input
    scanf("%c", &input);

    // Process the input
    switch (input) {
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
            append_number(input - '0');
            break;
        case '.':
            append_number(0);
            append_number(input - '0');
            break;
        case '=':
            calculate();
            break;
        case 'C':
            clear_buffer();
            break;
        default:
            enter_operator(input);
    }

    return 0;
}