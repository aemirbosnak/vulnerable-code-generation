//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct Calculator {
    int history[MAX_HISTORY];
    int historyPos;
    float number;
    char operator;
} Calculator;

Calculator calculator;

void initCalculator() {
    calculator.historyPos = 0;
    calculator.number = 0.0f;
    calculator.operator = '\0';
}

void addToHistory(float number) {
    if (calculator.historyPos >= MAX_HISTORY) {
        return;
    }
    calculator.history[calculator.historyPos++] = number;
}

void calculate(char operator, float number) {
    switch (operator) {
        case '+':
            calculator.number += number;
            break;
        case '-':
            calculator.number -= number;
            break;
        case '*':
            calculator.number *= number;
            break;
        case '/':
            if (number == 0) {
                return;
            }
            calculator.number /= number;
            break;
        default:
            return;
    }
    addToHistory(calculator.number);
}

int main() {
    initCalculator();

    char operator;
    float number;

    printf("Enter operator (+, -, *, /, =): ");
    scanf("%c", &operator);

    if (operator == '=') {
        printf("Result: %.2f\n", calculator.number);
    } else {
        printf("Enter number: ");
        scanf("%f", &number);
        calculate(operator, number);
        printf("Result: %.2f\n", calculator.number);
    }

    return 0;
}