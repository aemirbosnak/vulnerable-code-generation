//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int index;
    double result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->index = 0;
    calculator->result = 0.0;
    return calculator;
}

void calculator_add(Calculator* calculator, double number) {
    calculator->buffer[calculator->index++] = number;
    calculator->result += number;
}

void calculator_sub(Calculator* calculator, double number) {
    calculator->buffer[calculator->index++] = number;
    calculator->result -= number;
}

void calculator_mul(Calculator* calculator, double number) {
    calculator->buffer[calculator->index++] = number;
    calculator->result *= number;
}

void calculator_div(Calculator* calculator, double number) {
    calculator->buffer[calculator->index++] = number;
    calculator->result /= number;
}

void calculator_equal(Calculator* calculator) {
    double final_result = 0.0;
    for (int i = 0; i < calculator->index; i++) {
        final_result += calculator->buffer[i] * pow(10, calculator->index - i - 1);
    }
    calculator->result = final_result;
}

int main() {
    Calculator* calculator = calculator_init();

    // Example usage:
    calculator_add(calculator, 10);
    calculator_add(calculator, 20);
    calculator_mul(calculator, 2);
    calculator_div(calculator, 4);
    calculator_equal(calculator);

    // Print the result:
    printf("The result is: %.2lf\n", calculator->result);

    return 0;
}