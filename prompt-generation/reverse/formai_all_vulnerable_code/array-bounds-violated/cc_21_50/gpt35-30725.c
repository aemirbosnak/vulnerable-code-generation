//FormAI DATASET v1.0 Category: Syntax parsing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[128];
    printf("Enter C code to be parsed:\n");
    fgets(input, 128, stdin);

    // Check for suspicious characters
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '(' && input[i + 1] == ')') {
            printf("Error: Empty function call detected.\n");
            return 1;
        }

        if (input[i] == '<' && input[i + 1] == '<' && input[i + 2] == '=') {
            printf("Error: Bitwise left shift and assignment detected.\n");
            return 1;
        }

        if (input[i] == '>' && input[i + 1] == '>' && input[i + 2] == '=') {
            printf("Error: Bitwise right shift and assignment detected.\n");
            return 1;
        }

        if (input[i] == '=' && input[i + 1] == '=') {
            printf("Error: Double equals sign detected. Use \"==\" for comparison.\n");
            return 1;
        }

        if (input[i] == '+' && input[i + 1] == '+') {
            printf("Error: Unary plus operator detected.\n");
            return 1;
        }

        if (input[i] == '-' && input[i + 1] == '-') {
            printf("Error: Unary minus operator detected.\n");
            return 1;
        }

        if (input[i] == '&' && input[i + 1] == '&') {
            printf("Error: Logical AND operator detected. Use \"&\" for bitwise AND.\n");
            return 1;
        }

        if (input[i] == '|' && input[i + 1] == '|') {
            printf("Error: Logical OR operator detected. Use \"|\" for bitwise OR.\n");
            return 1;
        }

        if (input[i] == ';' && input[i + 1] != '\n') {
            printf("Error: Missing newline after semicolon.\n");
            return 1;
        }

        if (input[i] == '/' && input[i + 1] == '*') {
            printf("Error: C-style comment detected. Use // or /* ... */.\n");
            return 1;
        }

        if (input[i] == '\"' && input[i - 1] != '\\' && strchr(input + i + 1, '\"') == NULL) {
            printf("Error: Unterminated string detected.\n");
            return 1;
        }

        if (input[i] == '\'' && input[i - 1] != '\\' && strchr(input + i + 1, '\'') == NULL) {
            printf("Error: Unterminated character constant detected.\n");
            return 1;
        }
    }

    // Check for unbalanced symbols
    int parentheses_count = 0;
    int braces_count = 0;
    int brackets_count = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            parentheses_count++;
        } else if (input[i] == ')') {
            parentheses_count--;
        } else if (input[i] == '{') {
            braces_count++;
        } else if (input[i] == '}') {
            braces_count--;
        } else if (input[i] == '[') {
            brackets_count++;
        } else if (input[i] == ']') {
            brackets_count--;
        }

        if (parentheses_count < 0) {
            printf("Error: Unbalanced parentheses.\n");
            return 1;
        }

        if (braces_count < 0) {
            printf("Error: Unbalanced braces.\n");
            return 1;
        }

        if (brackets_count < 0) {
            printf("Error: Unbalanced brackets.\n");
            return 1;
        }
    }

    if (parentheses_count > 0) {
        printf("Error: Unbalanced parentheses.\n");
        return 1;
    }

    if (braces_count > 0) {
        printf("Error: Unbalanced braces.\n");
        return 1;
    }

    if (brackets_count > 0) {
        printf("Error: Unbalanced brackets.\n");
        return 1;
    }

    printf("No errors detected in input.\n");
    return 0;
}