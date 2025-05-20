//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_HISTORY 10

typedef struct CalculatorHistory {
    char operator;
    double operand1;
    double operand2;
    double result;
} CalculatorHistory;

CalculatorHistory history[MAX_HISTORY];
int historyIndex = 0;

void addHistory(char operator, double operand1, double operand2, double result) {
    if (historyIndex >= MAX_HISTORY) {
        return;
    }

    history[historyIndex].operator = operator;
    history[historyIndex].operand1 = operand1;
    history[historyIndex].operand2 = operand2;
    history[historyIndex].result = result;
    historyIndex++;
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
            }
            return operand1 / operand2;
        default:
            return -1;
    }
}

int main() {
    double number1, number2, result;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter the first operand: ");
    scanf("%lf", &number1);

    printf("Enter the second operand: ");
    scanf("%lf", &number2);

    result = calculate(operator, number1, number2);

    if (result != -1) {
        addHistory(operator, number1, number2, result);
        printf("The result is: %.2lf\n", result);
    } else {
        printf("Error: Invalid operation or division by zero.\n");
    }

    return 0;
}