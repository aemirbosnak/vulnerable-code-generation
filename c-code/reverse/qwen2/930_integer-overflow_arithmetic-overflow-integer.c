#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top <= -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluate(char *expression) {
    int i, num = 0, op1, op2;
    char token;

    for (i = 0; expression[i]; i++) {
        token = expression[i];

        if (isdigit(token)) {
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i++] - '0');
            }
            push(num);
            num = 0;
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            op2 = pop();
            op1 = pop();

            switch (token) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    return pop();
}

int main() {
    char expression[100];

    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}
