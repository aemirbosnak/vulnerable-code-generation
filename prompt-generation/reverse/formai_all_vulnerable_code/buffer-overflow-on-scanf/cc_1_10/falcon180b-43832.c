//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 100
#define BUFFER_SIZE 100

// Stack data structure
typedef struct {
    char value[BUFFER_SIZE];
    int index;
} Stack;

// Function declarations
void push(Stack* stack, char value);
char pop(Stack* stack);
void clear(Stack* stack);

// Main function
int main() {
    Stack stack;
    char input[BUFFER_SIZE];
    int i = 0;

    clear(&stack);

    while (1) {
        printf("Enter an expression or type 'q' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        // Reverse the input string
        for (int j = strlen(input) - 1; j >= 0; j--) {
            input[i++] = input[j];
        }
        input[i] = '\0';

        // Evaluate the expression
        for (int j = 0; input[j]!= '\0'; j++) {
            if (input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/') {
                push(&stack, input[j]);
            } else if (input[j] >= '0' && input[j] <= '9') {
                push(&stack, input[j]);
            } else if (input[j] == '(') {
                // Do nothing
            } else if (input[j] == ')') {
                while (stack.value[stack.index - 1]!= '(') {
                    char value = pop(&stack);
                    printf("%c", value);
                }
                pop(&stack);
            }
        }

        // Evaluate the remaining operators
        while (stack.index > 0) {
            char value = pop(&stack);
            printf("%c", value);
        }
        printf("\n");
    }

    return 0;
}

// Push a value onto the stack
void push(Stack* stack, char value) {
    if (stack->index >= STACK_SIZE) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->value[stack->index++] = value;
}

// Pop a value from the stack
char pop(Stack* stack) {
    if (stack->index <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->value[--stack->index];
}

// Clear the stack
void clear(Stack* stack) {
    stack->index = 0;
}