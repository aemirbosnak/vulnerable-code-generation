//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 50

int stack[MAX_LENGTH];
int top = -1;

void push(double value) {
    top++;
    stack[top] = value;
}

double pop() {
    double value = stack[top];
    top--;
    return value;
}

double peek() {
    return stack[top];
}

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_LENGTH - 1;
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int evaluate_postfix(char* expression) {
    int i = 0;
    while (expression[i]!= '\0') {
        if (isdigit(expression[i])) {
            push(atoi(expression + i));
            while (isdigit(expression[i])) {
                i++;
            }
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/' ||
                   expression[i] == '^') {
            while (!is_empty() && precedence(expression[i]) <= precedence(peek())) {
                double right = pop();
                double left = pop();
                switch (expression[i]) {
                    case '+':
                        push(left + right);
                        break;
                    case '-':
                        push(left - right);
                        break;
                    case '*':
                        push(left * right);
                        break;
                    case '/':
                        push(left / right);
                        break;
                    case '^':
                        push(pow(left, right));
                        break;
                }
            }
            push(expression[i]);
        }
        i++;
    }
    while (!is_empty()) {
        printf("%f ", pop());
    }
    printf("\n");
    return 0;
}

int main() {
    char expression[MAX_LENGTH];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    evaluate_postfix(expression);
    return 0;
}