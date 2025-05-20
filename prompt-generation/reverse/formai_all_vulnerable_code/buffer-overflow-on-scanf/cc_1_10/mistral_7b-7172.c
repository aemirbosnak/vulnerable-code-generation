//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

typedef struct Stack {
    int top;
    unsigned char data[MAX_SIZE];
} Stack;

void push(Stack *stack, unsigned char item) {
    stack->data[stack->top++] = item;
}

unsigned char pop(Stack *stack) {
    return stack->data[--stack->top];
}

int is_palindrome(char *str, int length) {
    Stack *stack = malloc(sizeof(Stack));
    int i;

    for (i = 0; i < length / 2; i++) {
        push(stack, str[i]);
        str[i] = str[length - i - 1];
    }

    if (length % 2 == 1) {
        if (stack->data[0] != str[length / 2]) {
            free(stack);
            return 0;
        }
        length--;
    }

    for (i = length / 2; i >= 0; i--) {
        if (stack->data[i] != str[i]) {
            free(stack);
            return 0;
        }
    }

    free(stack);
    return 1;
}

int main() {
    char str[MAX_SIZE];
    int length;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    if (is_palindrome(str, length))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}