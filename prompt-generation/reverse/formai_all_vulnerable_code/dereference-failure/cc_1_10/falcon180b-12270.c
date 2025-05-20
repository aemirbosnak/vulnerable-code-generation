//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 10

typedef struct {
    char* value;
    int precedence;
} StackElement;

typedef struct {
    StackElement elements[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, char* value, int precedence) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->elements[++stack->top] = (StackElement) {value, precedence};
}

StackElement pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack->elements[stack->top--];
}

void evaluate(Stack* stack) {
    StackElement left, right;
    char* result = malloc(100); // Allocate memory for result

    while (stack->top >= 2) {
        left = pop(stack);
        right = pop(stack);
        if (left.precedence > right.precedence) {
            push(stack, result, left.precedence);
            result = left.value;
        } else {
            push(stack, result, right.precedence);
            result = right.value;
        }
    }

    printf("%s = %s\n", left.value, result);
}

int main() {
    Stack stack;
    stack.top = -1;

    char* expression = "(2 + 3) * (4 - 1)";
    char* token;
    char* saveptr = NULL;

    for (token = strtok_r(expression, " ", &saveptr);
         token!= NULL;
         token = strtok_r(NULL, " ", &saveptr)) {
        if (isdigit(token[0])) {
            push(&stack, token, 0);
        } else {
            switch (token[0]) {
                case '+': case '-': case '*': case '/':
                    push(&stack, token, 1);
                    break;
                case '(':
                    push(&stack, token, 2);
                    break;
                case ')':
                    while (stack.top >= 0 && stack.elements[stack.top].value[0]!= '(') {
                        evaluate(&stack);
                    }
                    pop(&stack);
                    break;
            }
        }
    }

    while (stack.top >= 0) {
        evaluate(&stack);
    }

    return 0;
}