//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void push(char *stack, int top, char value) {
    if (top >= MAX_SIZE) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

char pop(char *stack, int *top) {
    if (*top <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[(*top)--];
}

int is_empty(int top) {
    return top == 0;
}

void print_stack(char *stack, int top) {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_SIZE];
    int top = -1, i, j;
    printf("Enter a binary number: ");
    scanf("%s", input);
    for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
        if (input[i] == '1') {
            push(input, ++top, '1');
        } else {
            push(input, ++top, '0');
        }
    }
    printf("The decimal equivalent is: ");
    while (!is_empty(top)) {
        printf("%c", pop(input, &top));
    }
    return 0;
}