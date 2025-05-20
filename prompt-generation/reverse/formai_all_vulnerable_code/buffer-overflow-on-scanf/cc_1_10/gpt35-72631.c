//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT 100

typedef struct _Node {
    double value;
    struct _Node *next;
} Node;

typedef struct _Stack {
    Node *top;
} Stack;

void push(Stack *stack, double value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

double pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    double value = stack->top->value;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

char* read_input() {
    char *input = (char *) malloc(MAX_INPUT * sizeof(char));
    scanf("%s", input);
    return input;
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int get_precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}

double evaluate(double a, double b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    else if (op == '^')
        return pow(a, b);
    else
        return 0;
}

double evaluate_postfix(char *expression) {
    Stack stack;
    stack.top = NULL;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            double value = expression[i] - '0';

            while (isdigit(expression[i + 1])) {
                value = value * 10 + (expression[++i] - '0');
            }
            push(&stack, value);
        } else if (is_operator(expression[i])) {
            double b = pop(&stack);
            double a = pop(&stack);
            double result = evaluate(a, b, expression[i]);
            push(&stack, result);
        }
    }
    return pop(&stack);
}

char* infix_to_postfix(char *expression) {
    Stack stack;
    stack.top = NULL;
    char *postfix = (char *) malloc(MAX_INPUT * sizeof(char));
    int j = 0;

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            postfix[j++] = expression[i];

            while (isdigit(expression[i + 1])) {
                postfix[j++] = expression[++i];
            }
            postfix[j++] = ' ';
        } else if (is_operator(expression[i])) {
            while (stack.top != NULL && get_precedence(expression[i]) <= get_precedence(stack.top->value)) {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, expression[i]);
        } else if (expression[i] == '(') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')') {
            while (stack.top != NULL && stack.top->value != '(') {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            pop(&stack);
        }
    }

    while (stack.top != NULL) {
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }
    postfix[j++] = '\0';
    return postfix;
}

int main() {
    printf("Enter an arithmetic expression: ");
    char *input = read_input();
    char *postfix = infix_to_postfix(input);
    double result = evaluate_postfix(postfix);
    printf("Result = %.2f\n", result);
    free(input);
    free(postfix);
    return 0;
}