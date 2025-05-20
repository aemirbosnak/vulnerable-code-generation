//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the input string from the user.
    char *input = malloc(1024);
    printf("Enter a string: ");
    scanf(" %s", input);

    // Create a stack to store the characters of the input string.
    char *stack[1024];
    int top = -1;

    // Push the characters of the input string onto the stack.
    for (int i = 0; input[i] != '\0'; i++) {
        stack[++top] = input + i;
    }

    // Create a buffer to store the reversed input string.
    char *reversed = malloc(1024);
    int j = 0;

    // Pop the characters from the stack and store them in the reversed buffer.
    while (top >= 0) {
        reversed[j++] = *stack[top--];
    }

    // Check if the input string is a palindrome.
    int is_palindrome = 1;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != reversed[i]) {
            is_palindrome = 0;
            break;
        }
    }

    // Print the result.
    if (is_palindrome) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    // Free the allocated memory.
    free(input);
    free(reversed);

    return 0;
}