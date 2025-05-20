//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *data;
} Stack;

Stack* create_stack(int size) {
    Stack *new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->size = size;
    new_stack->data = (int*)malloc(sizeof(int) * size);
    return new_stack;
}

void push(Stack *stack, int data) {
    if (stack->size == stack->data[0]) {
        int *new_data = (int*)realloc(stack->data, sizeof(int) * (stack->size + 1));
        if (new_data == NULL) {
            printf("Error: cannot realloc memory\n");
            exit(1);
        }
        stack->data = new_data;
        stack->size++;
    }
    stack->data[++stack->data[0]] = data;
}

int pop(Stack *stack) {
    if (stack->data[0] == 0) {
        printf("Error: stack is empty\n");
        exit(1);
    }
    return stack->data[stack->data[0]--];
}

void print_stack(Stack *stack) {
    if (stack->data[0] == 0) {
        printf("Empty stack\n");
    } else {
        printf("Stack: ");
        for (int i = stack->data[0]; i >= 0; i--) {
            printf("%d ", stack->data[i]);
        }
        printf("\n");
    }
}

void hanoi(Stack *source, Stack *destination, Stack *helper, int n) {
    if (n == 1) {
        push(destination, pop(source));
        return;
    }
    hanoi(source, helper, destination, n - 1);
    push(destination, pop(source));
    hanoi(helper, destination, source, n - 1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    Stack *source = create_stack(n);
    Stack *destination = create_stack(n);
    Stack *helper = create_stack(n);

    for (int i = n - 1; i >= 0; i--) {
        push(source, i + 1);
    }

    printf("Initial configuration:\n");
    print_stack(source);
    print_stack(destination);
    print_stack(helper);

    hanoi(source, destination, helper, n);

    printf("Final configuration:\n");
    print_stack(source);
    print_stack(destination);
    print_stack(helper);

    return 0;
}