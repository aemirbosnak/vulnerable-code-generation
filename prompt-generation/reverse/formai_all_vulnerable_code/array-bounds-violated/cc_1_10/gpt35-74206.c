//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

double num_stack[MAX_SIZE];
char op_stack[MAX_SIZE];
int num_top = -1, op_top = -1;

int get_precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

void push_num(double num) {
    if (num_top == MAX_SIZE - 1) {
        printf("Error: Stack is full!\n");
        exit(EXIT_FAILURE);
    }
    num_stack[++num_top] = num;
}

double pop_num() {
    if (num_top == -1) {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return num_stack[num_top--];
}

void push_op(char op) {
    if (op_top == MAX_SIZE - 1) {
        printf("Error: Stack is full!\n");
        exit(EXIT_FAILURE);
    }
    op_stack[++op_top] = op;
}

char pop_op() {
    if (op_top == -1) {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return op_stack[op_top--];
}

double calc(double a, double b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else if (op == '/') {
        return a / b;
    } else if (op == '^') {
        return pow(a, b);
    }
}

double evaluate(char *expr) {
    int i = 0;
    while (expr[i]) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            double num = c - '0';
            i++;
            while (expr[i] >= '0' && expr[i] <= '9') {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            if (expr[i] == '.') {
                double decimal = 0.1;
                i++;
                while (expr[i] >= '0' && expr[i] <= '9') {
                    num += (expr[i] - '0') * decimal;
                    decimal *= 0.1;
                    i++;
                }
            }
            push_num(num);
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int current_prec = get_precedence(c);
            while (op_top != -1 && get_precedence(op_stack[op_top]) >= current_prec) {
                char op = pop_op();
                double b = pop_num();
                double a = pop_num();
                double res = calc(a, b, op);
                push_num(res);
            }
            push_op(c);
            i++;
        } else if (c == '(') {
            push_op(c);
            i++;
        } else if (c == ')') {
            while (op_stack[op_top] != '(') {
                char op = pop_op();
                double b = pop_num();
                double a = pop_num();
                double res = calc(a, b, op);
                push_num(res);
            }
            pop_op();
            i++;
        } else {
            printf("Invalid character: %c\n", c);
            exit(EXIT_FAILURE);
        }
    }
    while (op_top != -1) {
        char op = pop_op();
        double b = pop_num();
        double a = pop_num();
        double res = calc(a, b, op);
        push_num(res);
    }
    return pop_num();
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter expression: ");
    fgets(expr, MAX_SIZE, stdin);
    double res = evaluate(expr);
    printf("Result: %f\n", res);
    return 0;
}