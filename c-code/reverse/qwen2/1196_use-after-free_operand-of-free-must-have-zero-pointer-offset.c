#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parseString(const char* str) {
    int stack[1024];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                printf("Unmatched closing %c\n", str[i]);
                continue;
            }
            char match = stack[top--];
            if ((match == '(' && str[i] != ')') ||
                (match == '{' && str[i] != '}') ||
                (match == '[' && str[i] != ']')) {
                printf("Mismatched %c with %c\n", match, str[i]);
            }
        }
    }
    if (top != -1) {
        printf("Unmatched opening ");
        while (top >= 0) {
            printf("%c ", stack[top--]);
        }
        printf("\n");
    }
}

int main() {
    const char* testStr = "({[]})";
    parseString(testStr);
    return 0;
}
