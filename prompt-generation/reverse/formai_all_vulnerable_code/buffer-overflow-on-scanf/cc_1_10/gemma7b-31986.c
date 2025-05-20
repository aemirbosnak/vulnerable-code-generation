//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 20

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

void initCalculator(Calculator *calc) {
    calc->pos = 0;
    calc->historyPos = 0;
    memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void addToBuffer(Calculator *calc, char ch) {
    if (calc->pos >= MAX_BUFFER_SIZE - 1) {
        return;
    }
    calc->buffer[calc->pos++] = ch;
}

void clearBuffer(Calculator *calc) {
    calc->pos = 0;
    memset(calc->buffer, 0, MAX_BUFFER_SIZE);
}

void addToHistory(Calculator *calc, char operator) {
    if (calc->historyPos >= 10) {
        return;
    }
    calc->history[calc->historyPos++] = operator;
}

double calculate(Calculator *calc) {
    char *expression = calc->buffer;
    int i = 0;
    double result = 0.0;
    double number1 = 0.0;
    double number2 = 0.0;
    char operator = '\0';

    for (; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            number1 = number1 * 10 + expression[i] - '0';
        } else if (operator == '\0') {
            operator = expression[i];
            number2 = number1;
            number1 = 0.0;
        } else {
            switch (operator) {
                case '+':
                    result = number2 + number1;
                    break;
                case '-':
                    result = number2 - number1;
                    break;
                case '*':
                    result = number2 * number1;
                    break;
                case '/':
                    if (number1 == 0) {
                        return -1;
                    }
                    result = number2 / number1;
                    break;
            }
            addToHistory(calc, operator);
            clearBuffer(calc);
            number1 = result;
        }
    }

    return result;
}

int main() {
    Calculator calc;
    initCalculator(&calc);

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    char *p = input;
    while (*p) {
        if (isdigit(*p)) {
            addToBuffer(&calc, *p);
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            addToBuffer(&calc, *p);
            addToHistory(&calc, *p);
            clearBuffer(&calc);
        }
        p++;
    }

    double result = calculate(&calc);

    if (result == -1) {
        printf("Error: division by zero\n");
    } else {
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}