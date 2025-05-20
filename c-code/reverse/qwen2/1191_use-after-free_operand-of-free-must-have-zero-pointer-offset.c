#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_string(const char *str) {
    int len = strlen(str);
    char *token = strtok((char *)str, " ");
    while (token != NULL) {
        if (token[0] == '(' && token[strlen(token) - 1] == ')') {
            printf("Balanced parentheses: %s\n", token);
        } else if (token[0] == '{' && token[strlen(token) - 1] == '}') {
            printf("Balanced braces: %s\n", token);
        } else if (token[0] == '[' && token[strlen(token) - 1] == ']') {
            printf("Balanced brackets: %s\n", token);
        }
        free(token); // Free the allocated memory for each token
        token = strtok(NULL, " ");
    }
}

int main() {
    const char *test_str = "( ) { } [ ]";
    parse_string(test_str);
    return 0;
}
