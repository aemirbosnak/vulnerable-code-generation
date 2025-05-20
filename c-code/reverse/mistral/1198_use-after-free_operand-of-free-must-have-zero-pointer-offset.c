#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_brackets(char *str) {
    int depth = 0, i;
    char *token;

    for (i = 0; (token = strtok(str, "{}[]()")); i++) {
        switch (*token) {
            case '(':
            case '[':
            case '{':
                depth++;
                printf("%c: depth increased to %d\n", *token, depth);
                break;
            case ')':
            case ']':
            case '}':
                if (depth > 0) {
                    depth--;
                    printf("%c: depth decreased to %d\n", *token, depth);
                } else {
                    printf("Use-after-free vulnerability: unexpected closing bracket %c\n", *token);
                }
                free(token);
                break;
        }
    }
}

int main() {
    char str[] = "{(())[[]]}";
    parse_brackets(str);
    return 0;
}
