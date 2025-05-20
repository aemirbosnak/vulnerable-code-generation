//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int top;
    char operator;
    double result;
} Calculator;

void calculate(Calculator *calc) {
    switch (calc->operator) {
        case '+':
            calc->result = atof(calc->buffer) + calc->result;
            break;
        case '-':
            calc->result = atof(calc->buffer) - calc->result;
            break;
        case '*':
            calc->result = atof(calc->buffer) * calc->result;
            break;
        case '/':
            if (calc->result == 0) {
                printf("Cannot divide by zero\n");
                return;
            }
            calc->result = atof(calc->buffer) / calc->result;
            break;
    }

    sprintf(calc->buffer, "%f", calc->result);
    calc->top = 0;
}

int main() {
    Calculator calc;
    calc.top = 0;
    calc.operator = '\0';
    calc.result = 0.0;

    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    // Parse the input expression
    char *token = strtok(input, " ");

    while (token) {
        if (token[0] >= 'a' && token[0] <= 'z') {
            // Insert the letter into the buffer
            calc.buffer[calc.top++] = token[0];
        } else if (token[0] >= '0' && token[0] <= '9') {
            // Insert the number into the buffer
            calc.buffer[calc.top++] = token[0];
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            // Store the operator
            calc.operator = token[0];
        }
        token = strtok(NULL, " ");
    }

    // Calculate the result
    calculate(&calc);

    // Print the result
    printf("The result is: %s\n", calc.buffer);

    return 0;
}