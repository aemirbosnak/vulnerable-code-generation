#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void analyze_code(const char *code) {
    int in_loop = 0;
    for (int i = 0; code[i] != '\0'; ++i) {
        if (strncasecmp(&code[i], "int", 3) == 0 || strncasecmp(&code[i], "float", 5) == 0 || strncasecmp(&code[i], "char", 4) == 0) {
            printf("Data type: %.*s\n", strcspn(&code[i], " \t"), &code[i]);
        } else if (strncasecmp(&code[i], "for", 3) == 0 || strncasecmp(&code[i], "while", 5) == 0 || strncasecmp(&code[i], "switch", 6) == 0) {
            printf("Loop structure: %.*s\n", strcspn(&code[i], " \t"), &code[i]);
        }
    }
}

int main() {
    char code[MAX_INPUT_SIZE];
    printf("Enter a line of C code: ");
    fgets(code, sizeof(code), stdin);
    analyze_code(code);
    return 0;
}
