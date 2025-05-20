#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_CODE_LENGTH 1024

void parse_code(const char *code) {
    int in_loop = 0;
    for (int i = 0; i < strlen(code); ++i) {
        if (strncmp(&code[i], "for", 3) == 0 || strncmp(&code[i], "while", 5) == 0) {
            printf("Loop construct found at position: %d\n", i);
            in_loop = 1;
        } else if (in_loop && (strncmp(&code[i], "{", 1) == 0)) {
            printf("Loop block starts at position: %d\n", i);
            in_loop = 0;
        }
        if (strncmp(&code[i], "int ", 4) == 0 || strncmp(&code[i], "char ", 5) == 0 ||
            strncmp(&code[i], "float ", 6) == 0 || strncmp(&code[i], "double ", 7) == 0) {
            printf("Data type found at position: %d\n", i);
        }
    }
}

int main() {
    char code[MAX_CODE_LENGTH];
    printf("Enter your C code snippet:\n");
    fgets(code, sizeof(code), stdin);
    parse_code(code);
    return 0;
}
