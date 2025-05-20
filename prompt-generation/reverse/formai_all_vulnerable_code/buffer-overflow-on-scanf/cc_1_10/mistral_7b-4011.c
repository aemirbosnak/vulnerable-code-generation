//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NUM 50
#define TRUE 1
#define FALSE 0

typedef struct {
    int num[MAX_NUM];
    int top;
} Stack;

void initialize_stack(Stack *stack) {
    stack->top = -1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int value) {
    if (stack->top >= MAX_NUM - 1) {
        fprintf(stderr, "Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->num[++stack->top] = value;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->num[stack->top--];
}

void calculate_postfix(char *expression) {
    Stack calculator;
    initialize_stack(&calculator);

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            push(&calculator, expression[i] - '0');
        } else if (strchr(" +-*/^", expression[i])) {
            int right_operand = pop(&calculator);
            int left_operand = pop(&calculator);

            switch (expression[i]) {
                case '+':
                    push(&calculator, left_operand + right_operand);
                    break;
                case '-':
                    push(&calculator, left_operand - right_operand);
                    break;
                case '*':
                    push(&calculator, left_operand * right_operand);
                    break;
                case '/':
                    push(&calculator, left_operand / right_operand);
                    break;
                case '^':
                    push(&calculator, pow(left_operand, right_operand));
                    break;
            }
        }
    }

    if (calculator.top != 0) {
        fprintf(stderr, "Invalid postfix expression.\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", calculator.num[0]);
}

int main() {
    char postfix[MAX_NUM];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    calculate_postfix(postfix);

    return 0;
}