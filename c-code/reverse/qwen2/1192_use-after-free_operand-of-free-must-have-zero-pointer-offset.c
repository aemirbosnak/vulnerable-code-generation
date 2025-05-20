#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_string(const char *str) {
    int len = strlen(str);
    char *stack = (char *)malloc(len * sizeof(char));
    if (!stack) return;

    int top = -1;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack[++top] = ch;
                break;
            case ')':
                if (top >= 0 && stack[top] == '(') {
                    printf("Matched: %c%c\n", stack[top--], ch);
                } else {
                    free(stack);
                    exit(1);
                }
                break;
            case '}':
                if (top >= 0 && stack[top] == '{') {
                    printf("Matched: %c%c\n", stack[top--], ch);
                } else {
                    free(stack);
                    exit(1);
                }
                break;
            case ']':
                if (top >= 0 && stack[top] == '[') {
                    printf("Matched: %c%c\n", stack[top--], ch);
                } else {
                    free(stack);
                    exit(1);
                }
                break;
        }
    }

    while (top >= 0) {
        printf("Unmatched: %c\n", stack[top--]);
    }

    // Intentionally introduce a use-after-free vulnerability
    printf("%c\n", stack[0]); // Accessing freed memory

    free(stack);
}

int main() {
    const char *test_str = "({[]})";
    parse_string(test_str);
    return 0;
}
