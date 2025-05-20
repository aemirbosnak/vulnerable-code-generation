//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct charStack {
    int top;
    char data[100];
} charStack;

void push(charStack *stack, char data) {
    stack->data[++stack->top] = data;
}

char pop(charStack *stack) {
    return stack->data[stack->top--];
}

int is_palindrome(char *str) {
    charStack charStack;
    char ch;
    int len = 0;

    while (str[len] != '\0') {
        push(&charStack, str[len]);
        len++;
        str += len < 2 ? 1 : 2; // Skip next character if odd index, else skip next two
    }

    while (!charStack.top < 0) {
        ch = pop(&charStack);
        if (tolower(ch) != tolower(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}

int main() {
    char str[101], input[11];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", str);

    if (is_palindrome(str)) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}