//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_SIZE 100

typedef struct Stack {
    double values[MAX_STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, double value) {
    if (stack->top != MAX_STACK_SIZE - 1) {
        stack->top++;
        stack->values[stack->top] = value;
    }
    else {
        printf("Stack Overflow");
        exit(1);
    }
}

double pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow");
        exit(1);
    }
    else {
        double temp = stack->values[stack->top];
        stack->top--;
        return temp;
    }
}

double peek(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow");
        exit(1);
    }
    else {
        return stack->values[stack->top];
    } 
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice;
    double num, num1, num2;
    do {
        printf("Enter 1 for push, 2 for pop, 3 for peek, 4 for add, 5 for subtract, 6 for multiply, 7 for divide, 8 for exp, 9 for square root, 10 for sin, 11 for cos, 12 for tan, 13 for exit: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%lf", &num);
                push(&stack, num);
                break;
            case 2:
                num = pop(&stack);
                printf("%lf popped from the stack\n", num);
                break;
            case 3:
                num = peek(&stack);
                printf("%lf is at the top of the stack\n", num);
                break;
            case 4: 
                num1 = pop(&stack);
                num2 = pop(&stack);
                push(&stack, num1 + num2);
                printf("%lf\n", num1+num2);
                break;
            case 5: 
                num1 = pop(&stack);
                num2 = pop(&stack);
                push(&stack, num2 - num1);
                printf("%lf\n", num2-num1);
                break;
            case 6:
                num1 = pop(&stack);
                num2 = pop(&stack);
                push(&stack, num1 * num2);
                printf("%lf\n", num1*num2);
                break;
            case 7:
                num1 = pop(&stack);
                num2 = pop(&stack);
                push(&stack, num2 / num1);
                printf("%lf\n", num2/num1);
                break;
            case 8:
                num1 = pop(&stack);
                push(&stack, exp(num1));
                printf("%lf\n", exp(num1));
                break;
            case 9:
                num1 = pop(&stack);
                push(&stack, sqrt(num1));
                printf("%lf\n", sqrt(num1));
                break;
            case 10:
                num1 = pop(&stack);
                push(&stack, sin(num1));
                printf("%lf\n", sin(num1));
                break;
            case 11:
                num1 = pop(&stack);
                push(&stack, cos(num1));
                printf("%lf\n", cos(num1));
                break;
            case 12:
                num1 = pop(&stack);
                push(&stack, tan(num1));
                printf("%lf\n", tan(num1));
                break;
            case 13:
                printf("Exiting..");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    } while (1);

    return 0;
}