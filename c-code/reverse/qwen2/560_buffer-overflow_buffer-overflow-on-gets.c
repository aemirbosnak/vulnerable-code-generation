#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void parse_code(const char *code) {
    int in_loop = 0;
    for (int i = 0; code[i] != '\0'; ++i) {
        if (strchr("intfloatchar", code[i]) != NULL) {
            printf("%c ", code[i]);
        }
        if (strchr("forwhileswitch", code[i]) != NULL) {
            in_loop = 1;
        }
        if (in_loop && code[i] == ';') {
            in_loop = 0;
        }
    }
}

int main() {
    char code[256];
    printf("Enter C code: ");
    gets(code); // Intentional buffer overflow vulnerability
    parse_code(code);
    return 0;
}
