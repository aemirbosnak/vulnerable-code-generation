//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double value;
    char operator;
} stack_element;

typedef struct {
    stack_element *elements;
    int size;
    int top;
} stack;

stack *create_stack() {
    stack *new_stack = malloc(sizeof(stack));
    new_stack->elements = malloc(sizeof(stack_element) * MAX_STACK_SIZE);
    new_stack->size = MAX_STACK_SIZE;
    new_stack->top = -1;
    return new_stack;
}

void push(stack *s, double value, char operator) {
    if (s->top == s->size - 1) {
        printf("Error: Stack overflow.\n");
        return;
    }

    s->top++;
    s->elements[s->top].value = value;
    s->elements[s->top].operator = operator;
}

stack_element pop(stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow.\n");
        return (stack_element){0, '\0'};
    }

    return s->elements[s->top--];
}

double evaluate_expression(char *expression) {
    stack *s = create_stack();
    double result = 0;
    char *token;

    token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            double op1 = pop(s).value;
            double op2 = pop(s).value;
            char operator = token[0];

            switch (operator) {
                case '+':
                    result = op2 + op1;
                    break;
                case '-':
                    result = op2 - op1;
                    break;
                case '*':
                    result = op2 * op1;
                    break;
                case '/':
                    result = op2 / op1;
                    break;
            }

            push(s, result, '\0');
        } else {
            double value = atof(token);
            push(s, value, '\0');
        }

        token = strtok(NULL, " ");
    }

    result = pop(s).value;
    free(s);
    return result;
}

int main() {
    char expression[100];

    printf("Enter a mathematical expression: ");
    gets(expression);

    double result = evaluate_expression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}