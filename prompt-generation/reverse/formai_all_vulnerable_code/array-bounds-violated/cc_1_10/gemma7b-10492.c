//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int history_pos;
} calculator;

calculator calc;

void initialize_calculator() {
    calc.pos = 0;
    calc.history_pos = 0;
    calc.history[0] = 0;
}

void add_to_buffer(char c) {
    if (calc.pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc.buffer[calc.pos++] = c;
}

void clear_buffer() {
    calc.pos = 0;
}

void calculate() {
    char operator = calc.buffer[calc.pos - 1];
    double a = atof(calc.buffer);
    double b = atof(calc.buffer);
    double result = 0;

    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                return;
            }
            result = a / b;
            break;
        default:
            return;
    }

    add_to_buffer(result);
    clear_buffer();
}

int main() {
    initialize_calculator();

    char input;

    printf("Enter an expression: ");

    while ((input = getchar()) != '\n') {
        add_to_buffer(input);
    }

    calculate();

    printf("Result: %s\n", calc.buffer);

    return 0;
}