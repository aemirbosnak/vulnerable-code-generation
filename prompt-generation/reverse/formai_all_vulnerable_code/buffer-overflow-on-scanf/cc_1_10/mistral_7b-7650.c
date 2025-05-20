//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10

typedef struct {
    double numbers[MAX_SIZE];
    int top;
} Stack;

void initialize_stack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, double number) {
    if (stack->top >= MAX_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        return;
    }
    stack->numbers[++stack->top] = number;
}

double pop(Stack *stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Error: Stack underflow\n");
        return NAN;
    }
    return stack->numbers[stack->top--];
}

double calculate_expression(char *expression) {
    Stack stack;
    initialize_stack(&stack);
    double num1, num2, result;
    char operator;

    for (int i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            num1 = strtod(&expression[i], NULL);
            push(&stack, num1);
        } else if (isalnum(expression[i])) {
            operator = expression[i];
            num2 = pop(&stack);
            num1 = pop(&stack);

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
                        fprintf(stderr, "Error: Division by zero\n");
                        return NAN;
                    }
                    result = num1 / num2;
                    break;
                case '^':
                    result = pow(num1, num2);
                    break;
                default:
                    fprintf(stderr, "Error: Invalid operator\n");
                    return NAN;
            }

            push(&stack, result);
        }
    }

    if (stack.top != -1) {
        fprintf(stderr, "Error: Stack overflow\n");
        return NAN;
    }

    result = pop(&stack);
    return result;
}

int main() {
    char expression[100];
    double result;

    printf("Enter a mathematical expression (e.g., 3.14 + 2.71 * 5): ");
    scanf("%s", expression);

    result = calculate_expression(expression);

    if (isnan(result)) {
        perror("Error:");
    } else {
        printf("Result: %.2lf\n", result);
    }

    return 0;
}