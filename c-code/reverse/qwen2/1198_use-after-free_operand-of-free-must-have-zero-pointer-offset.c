#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parseString(const char *str) {
    int stack[100], top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1) {
                printf("Unbalanced\n");
                return;
            }
            char match = stack[top--];
            if ((match == '(' && str[i] != ')') ||
                (match == '{' && str[i] != '}') ||
                (match == '[' && str[i] != ']')) {
                printf("Unmatched %c with %c\n", match, str[i]);
                return;
            }
        }
    }
    if (top != -1) {
        printf("Unbalanced\n");
        return;
    }
    // Intentionally free the stack array to create a use-after-free vulnerability
    free(stack);
    // Potentially access freed memory here
    printf("%d\n", stack[0]); // This line is vulnerable
}

int main() {
    const char *testStr = "({[]})";
    parseString(testStr);
    return 0;
}
