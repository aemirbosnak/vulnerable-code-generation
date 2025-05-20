//Falcon-180B DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int *ptr;
    int size;
    int capacity;
} Stack;

void push(Stack *stack, int value) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->ptr = realloc(stack->ptr, stack->capacity * sizeof(int));
    }
    stack->ptr[stack->size++] = value;
}

int pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    return stack->ptr[--stack->size];
}

int main() {
    Stack stack;
    stack.ptr = NULL;
    stack.size = 0;
    stack.capacity = 0;

    int choice;
    do {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                printf("%d pushed to the stack.\n", value);
                break;
            }
            case 2: {
                int value = pop(&stack);
                printf("%d popped from the stack.\n", value);
                break;
            }
            case 3: {
                if (stack.size == 0) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack elements:\n");
                    for (int i = 0; i < stack.size; i++) {
                        printf("%d ", stack.ptr[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while (choice!= 4);

    return 0;
}