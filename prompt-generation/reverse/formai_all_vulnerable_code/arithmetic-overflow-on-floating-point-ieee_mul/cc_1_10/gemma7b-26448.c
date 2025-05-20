//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HISTORY 10

typedef struct Calculator {
    char history[MAX_HISTORY][255];
    int history_idx;
    double current_value;
    char operator;
} Calculator;

Calculator calculator;

void initialize_calculator() {
    calculator.history_idx = 0;
    calculator.current_value = 0.0;
    calculator.operator = '\0';
}

void store_history(char operation, double value) {
    if (calculator.history_idx >= MAX_HISTORY) {
        return;
    }

    sprintf(calculator.history[calculator.history_idx], "%c %f", operation, value);
    calculator.history_idx++;
}

double calculate(char operator, double value) {
    switch (operator) {
        case '+':
            return calculator.current_value + value;
        case '-':
            return calculator.current_value - value;
        case '*':
            return calculator.current_value * value;
        case '/':
            if (value == 0) {
                return -1;
            }
            return calculator.current_value / value;
        default:
            return -1;
    }
}

int main() {
    initialize_calculator();

    char operation;
    double value;

    printf("Enter an operation (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter a value: ");
    scanf("%lf", &value);

    calculator.operator = operation;
    calculator.current_value = value;

    store_history(operation, value);

    double result = calculate(operation, value);

    if (result == -1) {
        printf("Error!\n");
    } else {
        printf("The result is: %f\n", result);
    }

    return 0;
}