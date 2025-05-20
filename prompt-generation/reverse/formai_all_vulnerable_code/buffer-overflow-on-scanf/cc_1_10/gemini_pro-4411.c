//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

// Stack structure
typedef struct {
    double data[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, double value) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
double pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Function to perform a binary operation on the top two elements of the stack
double binaryOp(Stack *stack, char op) {
    double op1 = pop(stack);
    double op2 = pop(stack);
    switch (op) {
        case '+':
            return op1 + op2;
        case '-':
            return op2 - op1;
        case '*':
            return op1 * op2;
        case '/':
            if (op1 == 0) {
                printf("Division by zero.\n");
                exit(1);
            }
            return op2 / op1;
        case '^':
            return pow(op2, op1);
        default:
            printf("Invalid operator.\n");
            exit(1);
    }
}

// Function to evaluate a postfix expression
double evaluatePostfix(char *expr) {
    Stack stack;
    initStack(&stack);
    int i = 0;
    while (expr[i] != '\0') {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            double value = c - '0';
            push(&stack, value);
        } else {
            double result = binaryOp(&stack, c);
            push(&stack, result);
        }
        i++;
    }
    return pop(&stack);
}

// Function to get an operator from the user
char getOperator() {
    char op;
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf(" %c", &op);
    return op;
}

// Function to get an operand from the user
double getOperand() {
    double operand;
    printf("Enter an operand: ");
    scanf("%lf", &operand);
    return operand;
}

// Function to print the stack
void printStack(Stack *stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%lf ", stack->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char expr[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expr);
    double result = evaluatePostfix(expr);
    printf("Result: %lf\n", result);
    return 0;
}