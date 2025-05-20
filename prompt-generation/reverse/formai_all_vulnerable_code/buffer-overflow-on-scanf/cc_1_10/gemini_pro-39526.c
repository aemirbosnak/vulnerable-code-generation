//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        push(str[i]);
    }

    int is_palindrome = 1;
    for (int i = len / 2; i < len; i++) {
        if (str[i] != pop()) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}