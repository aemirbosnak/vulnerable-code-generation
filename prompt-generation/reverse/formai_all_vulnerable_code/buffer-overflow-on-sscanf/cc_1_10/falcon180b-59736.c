//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000
#define MAX_ELEMENT_SIZE 1000

typedef struct element {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
} Element;

typedef struct stack {
    Element elements[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, Element element) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack->elements[++stack->top] = element;
}

Element pop(Stack* stack) {
    if (stack->top <= 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack->elements[stack->top--];
}

int main(int argc, char* argv[]) {
    FILE* file;
    char buffer[MAX_ELEMENT_SIZE];
    Element element;
    Stack stack;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }

    stack.top = -1;

    while (fgets(buffer, MAX_ELEMENT_SIZE, file)!= NULL) {
        if (buffer[0] == '<') {
            sscanf(buffer, "<%[^>]>", element.name);
            push(&stack, element);
        } else if (buffer[0] == '>') {
            sscanf(buffer + 1, "%[^\n]", element.value);
            element.value[strcspn(element.value, "\n")] = '\0';
            push(&stack, element);
        }
    }

    fclose(file);

    while (stack.top >= 0) {
        element = pop(&stack);
        printf("Name: %s\nValue: %s\n", element.name, element.value);
    }

    return 0;
}