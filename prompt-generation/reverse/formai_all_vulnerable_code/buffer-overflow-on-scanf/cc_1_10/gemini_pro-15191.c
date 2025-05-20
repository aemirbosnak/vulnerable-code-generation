//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef enum {
    OP_NONE,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_POW,
    OP_SQRT,
    OP_SIN,
    OP_COS,
    OP_TAN
} OpType;

typedef struct {
    double value;
    OpType op;
} StackItem;

typedef struct {
    StackItem stack[MAX_STACK_SIZE];
    int top;
} Stack;

Stack stack;

void push(double value) {
    stack.stack[stack.top].value = value;
    stack.stack[stack.top].op = OP_NONE;
    stack.top++;
}

double pop() {
    stack.top--;
    return stack.stack[stack.top].value;
}

double peek() {
    return stack.stack[stack.top - 1].value;
}

void operate(OpType op) {
    double a, b;
    switch (op) {
        case OP_ADD:
            b = pop();
            a = pop();
            push(a + b);
            break;
        case OP_SUB:
            b = pop();
            a = pop();
            push(a - b);
            break;
        case OP_MUL:
            b = pop();
            a = pop();
            push(a * b);
            break;
        case OP_DIV:
            b = pop();
            a = pop();
            push(a / b);
            break;
        case OP_POW:
            b = pop();
            a = pop();
            push(pow(a, b));
            break;
        case OP_SQRT:
            a = pop();
            push(sqrt(a));
            break;
        case OP_SIN:
            a = pop();
            push(sin(a));
            break;
        case OP_COS:
            a = pop();
            push(cos(a));
            break;
        case OP_TAN:
            a = pop();
            push(tan(a));
            break;
    }
}

int main() {
    double value;
    char op;

    stack.top = 0;

    while (1) {
        printf("Enter a value or an operator (+, -, *, /, ^, sqrt, sin, cos, tan, q to quit): ");
        scanf(" %c", &op);

        if (op == 'q') {
            break;
        } else if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
            operate(op);
        } else if (op == 's' || op == 'c' || op == 't') {
            op += 'i' - 's';
            operate(op);
        } else if (op == 'r') {
            operate(OP_SQRT);
        } else {
            scanf(" %lf", &value);
            push(value);
        }

        printf("Stack: ");
        for (int i = 0; i < stack.top; i++) {
            printf("%f ", stack.stack[i].value);
        }
        printf("\n");
    }

    return 0;
}