#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_string(const char *str) {
    int len = strlen(str);
    char *stack = (char *)malloc(len + 1);
    if (!stack) return;

    int top = -1;
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack[++top] = ch;
                break;
            case ')':
                if (top >= 0 && stack[top] == '(') {
                    printf("Balanced: %c\n", ch);
                    top--;
                } else {
                    printf("Unbalanced: %c\n", ch);
                }
                break;
            case '}':
                if (top >= 0 && stack[top] == '{') {
                    printf("Balanced: %c\n", ch);
                    top--;
                } else {
                    printf("Unbalanced: %c\n", ch);
                }
                break;
            case ']':
                if (top >= 0 && stack[top] == '[') {
                    printf("Balanced: %c\n", ch);
                    top--;
                } else {
                    printf("Unbalanced: %c\n", ch);
                }
                break;
        }
    }

    // Intentional use-after-free vulnerability
    free(stack);
    printf("%c\n", stack[0]);  // Accessing freed memory

    while (top >= 0) {
        printf("Unmatched: %c\n", stack[top--]);
    }
}

int main() {
    const char *test_str = "({[]})";
    parse_string(test_str);
    return 0;
}
