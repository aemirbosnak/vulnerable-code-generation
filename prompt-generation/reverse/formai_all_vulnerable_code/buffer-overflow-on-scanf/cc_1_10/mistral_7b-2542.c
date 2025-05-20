//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct Stack {
    int top;
    char data[MAX_LENGTH];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char item) {
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    return stack->data[stack->top--];
}

int is_palindrome(char *str, int length) {
    Stack stack;
    int i;
    initialize(&stack);

    for (i = 0; i < length / 2; i++) {
        push(&stack, str[i]);
        str[i] = str[length - i - 1];
    }

    if (length % 2 == 1) {
        if (stack.data[0] != str[length / 2]) {
            return 0;
        }
        length--;
    }

    for (i = length / 2; i >= 0; i--) {
        if (stack.data[0] != str[i]) {
            return 0;
        }
        pop(&stack);
    }

    return 1;
}

int main(void) {
    char str[MAX_LENGTH];
    int length, palindrome;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    palindrome = is_palindrome(str, length);

    if (palindrome) {
        printf("The string '%s' is a palindrome.\n", str);
    } else {
        printf("The string '%s' is not a palindrome.\n", str);
    }

    if (length >= 2) {
        int palindrome_length = length / 2;
        char substring[MAX_LENGTH];

        strncpy(substring, str, palindrome_length + 1);

        if (is_palindrome(substring, palindrome_length)) {
            printf("The first half of the string '%s' is a palindrome.\n", str);
        } else {
            printf("The first half of the string '%s' is not a palindrome.\n", str);
        }
    }

    return 0;
}