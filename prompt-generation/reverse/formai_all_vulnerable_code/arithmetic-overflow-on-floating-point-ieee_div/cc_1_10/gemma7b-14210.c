//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HISTORY 10

typedef struct CalculatorHistory {
    char operator;
    double operand1;
    double operand2;
    double result;
} CalculatorHistory;

CalculatorHistory history[MAX_HISTORY];
int historyIndex = 0;

void addToHistory(char operator, double operand1, double operand2, double result) {
    history[historyIndex].operator = operator;
    history[historyIndex].operand1 = operand1;
    history[historyIndex].operand2 = operand2;
    history[historyIndex].result = result;
    historyIndex++;

    if (historyIndex == MAX_HISTORY) {
        historyIndex = 0;
    }
}

double calculate(char operator, double operand1, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                return -1;
            } else {
                return operand1 / operand2;
            }
        default:
            return -1;
    }
}

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to the Calculator!\n");

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the first operand: ");
    scanf(" %lf", &num1);

    printf("Enter the second operand: ");
    scanf(" %lf", &num2);

    result = calculate(operator, num1, num2);

    if (result == -1) {
        printf("Error!\n");
    } else {
        addToHistory(operator, num1, num2, result);
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}