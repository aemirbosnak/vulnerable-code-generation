//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LENGTH 1000
#define MAX_MODULES 100
#define MAX_MODULE_SIZE 10

typedef struct {
    int size;
    int top;
    int data[MAX_DATA_LENGTH];
} Stack;

void init_stack(Stack *stack) {
    stack->size = MAX_DATA_LENGTH;
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return (stack->top == -1);
}

int is_full(Stack *stack) {
    return (stack->top == stack->size - 1);
}

void push(Stack *stack, int data) {
    if (is_full(stack)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = data;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int data = stack->data[stack->top];
    stack->top--;
    return data;
}

void print_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    Stack module_stack;
    init_stack(&module_stack);

    while (fscanf(fp, "%d", &data)!= EOF) {
        if (is_full(&module_stack)) {
            printf("Module Overflow\n");
            exit(1);
        }
        push(&module_stack, data);
    }

    int modules = pop(&module_stack);

    fclose(fp);

    printf("Total modules: %d\n", modules);

    while (!is_empty(&module_stack)) {
        printf("Module size: %d\n", pop(&module_stack));
    }

    return 0;
}