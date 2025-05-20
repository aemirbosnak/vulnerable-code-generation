#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseString(const char *str) {
    int len = strlen(str);
    char *stack = (char *)malloc(len * sizeof(char));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                stack[++top] = ch;
                break;
            case ')':
                if (top >= 0 && stack[top] == '(') {
                    printf("Balanced: ()\n");
                    top--;
                } else {
                    printf("Unbalanced: )\n");
                }
                break;
            case '}':
                if (top >= 0 && stack[top] == '{') {
                    printf("Balanced: {}\n");
                    top--;
                } else {
                    printf("Unbalanced: }\n");
                }
                break;
            case ']':
                if (top >= 0 && stack[top] == '[') {
                    printf("Balanced: []\n");
                    top--;
                } else {
                    printf("Unbalanced: ]\n");
                }
                break;
        }
    }

    while (top >= 0) {
        printf("Unbalanced: %c\n", stack[top--]);
    }

    free(stack);
}

int main() {
    const char *testStr = "{[()]}";
    parseString(testStr);
    return 0;
}
