//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 20

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

void calculate(Calculator *calc) {
    char operator = calc->buffer[calc->pos - 1];
    int num1 = atoi(calc->buffer);
    int num2 = atoi(calc->buffer + calc->pos);
    int result = 0;

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
                return;
            }
            result = num1 / num2;
            break;
    }

    calc->history[calc->historyPos++] = result;
    sprintf(calc->buffer, "%d", result);
    calc->pos++;
}

int main() {
    Calculator calc;
    calc.pos = 0;
    calc.historyPos = 0;

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
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
                calc.buffer[calc.pos++] = input[i];
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                calculate(&calc);
                break;
        }
    }

    printf("Result: %s\n", calc.buffer);

    return 0;
}