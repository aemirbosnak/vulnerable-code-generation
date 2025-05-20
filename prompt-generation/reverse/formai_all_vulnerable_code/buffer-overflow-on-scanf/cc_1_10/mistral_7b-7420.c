//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 1024
#define MAX_STACK_SIZE 256

typedef struct {
    int top;
    char data[MAX_STACK_SIZE];
} Stack;

void initialize_stack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char data) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = data;
}

char pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int is_valid_char(char c) {
    return isalnum(c) || c == '.' || c == '_' || c == '-';
}

void sanitize_url(char *url) {
    Stack stack;
    initialize_stack(&stack);
    int length = strlen(url);
    int i = 0;

    for (; i < length; i++) {
        if (is_valid_char(url[i])) {
            push(&stack, url[i]);
        } else if (url[i] == ':' && i < length - 1 && is_valid_char(url[i + 1])) {
            push(&stack, url[i]);
            i++;
        } else {
            if (stack.top >= 0) {
                printf("%c", pop(&stack));
            }
        }

        if (i < length - 1 && (url[i] == '/' || url[i] == '?')) {
            printf("/");
            while (stack.top >= 0) {
                printf("%c", pop(&stack));
            }
            i++;
        }
    }

    while (stack.top >= 0) {
        printf("%c", pop(&stack));
    }

    printf("\n");
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL: ");
    scanf("%s", url);

    sanitize_url(url);

    return 0;
}