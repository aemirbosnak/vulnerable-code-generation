//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct _symmetric_pair {
    char c;
    int is_palindrome;
} symmetric_pair;

void recursive_compare(const char *str, int start, int end, symmetric_pair *stack, int stack_top);

int is_palindrome(const char *str) {
    int len = strlen(str);
    symmetric_pair stack[len];
    int stack_top = 0;

    recursive_compare(str, 0, len - 1, stack, stack_top);

    return stack[stack_top].is_palindrome;
}

void recursive_compare(const char *str, int start, int end, symmetric_pair *stack, int stack_top) {
    if (start >= end) {
        stack[stack_top].c = str[start];
        stack[stack_top].is_palindrome = 1;
        return;
    }

    recursive_compare(str, start + 1, end - 1, stack, stack_top + 1);

    if (str[start] != str[end]) {
        stack[stack_top].c = str[start];
        stack[stack_top].is_palindrome = 0;
        if (stack_top > 0 && stack[stack_top - 1].is_palindrome)
            return;
    }

    recursive_compare(str, start + 1, end - 1, stack, stack_top + 1);
}

int main() {
    char str[101];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_palindrome(str))
        printf("The given string is a palindrome.\n");
    else
        printf("The given string is not a palindrome.\n");

    return 0;
}