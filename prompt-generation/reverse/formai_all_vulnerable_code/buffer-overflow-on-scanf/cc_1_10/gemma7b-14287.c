//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    double accumulator;
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int state;
} Calculator;

Calculator* calculator_init() {
    Calculator* calculator = malloc(sizeof(Calculator));
    calculator->accumulator = 0;
    calculator->position = 0;
    calculator->state = 0;
    return calculator;
}

void calculator_add(Calculator* calculator, double number) {
    calculator->accumulator += number;
}

void calculator_subtract(Calculator* calculator, double number) {
    calculator->accumulator -= number;
}

void calculator_multiply(Calculator* calculator, double number) {
    calculator->accumulator *= number;
}

void calculator_divide(Calculator* calculator, double number) {
    if (number == 0) {
        printf("Error: division by zero is not allowed.\n");
        return;
    }
    calculator->accumulator /= number;
}

void calculator_clear(Calculator* calculator) {
    calculator->accumulator = 0;
    calculator->position = 0;
    calculator->state = 0;
}

int main() {
    Calculator* calculator = calculator_init();

    char input[MAX_BUFFER_SIZE];
    double number;

    printf("Enter an operation (add, subtract, multiply, divide, clear): ");
    scanf("%s", input);

    switch (input[0]) {
        case 'a':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_add(calculator, number);
            break;
        case 's':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_subtract(calculator, number);
            break;
        case 'm':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_multiply(calculator, number);
            break;
        case 'd':
            printf("Enter a number: ");
            scanf("%lf", &number);
            calculator_divide(calculator, number);
            break;
        case 'c':
            calculator_clear(calculator);
            break;
        default:
            printf("Invalid operation.\n");
    }

    printf("Accumulator: %.2lf\n", calculator->accumulator);

    free(calculator);

    return 0;
}