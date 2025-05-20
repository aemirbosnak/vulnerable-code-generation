//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
    char operator;
} Calculator;

Calculator calculator;

void calculate(char operator, int num) {
    switch (operator) {
        case '+':
            calculator.buffer[calculator.pos++] = '+';
            calculator.buffer[calculator.pos++] = num + '0' + '0';
            break;
        case '-':
            calculator.buffer[calculator.pos++] = '-';
            calculator.buffer[calculator.pos++] = num + '0' + '0';
            break;
        case '*':
            calculator.buffer[calculator.pos++] = '*';
            calculator.buffer[calculator.pos++] = num + '0' + '0';
            break;
        case '/':
            calculator.buffer[calculator.pos++] = '/';
            calculator.buffer[calculator.pos++] = num + '0' + '0';
            break;
        default:
            break;
    }
}

void storeHistory(int num) {
    if (calculator.historyPos == 10) {
        calculator.historyPos = 0;
    }
    calculator.history[calculator.historyPos++] = num;
}

int main() {
    char input[MAX_BUFFER_SIZE];
    int num1, num2;
    char operator;

    printf("Enter an expression: ");
    scanf("%s", input);

    calculator.pos = 0;
    calculator.historyPos = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            num1 = input[i] - '0';
            calculate('+', num1);
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            operator = input[i];
            num2 = input[i+1] - '0';
            calculate(operator, num2);
            storeHistory(num2);
        }
    }

    printf("Result: %s\n", calculator.buffer);

    return 0;
}