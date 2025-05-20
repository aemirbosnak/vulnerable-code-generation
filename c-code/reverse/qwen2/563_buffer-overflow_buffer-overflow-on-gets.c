#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char code[1000];
    printf("Enter C source code: ");
    gets(code);

    int i = 0;
    while (code[i] != '\0') {
        if (strncmp(&code[i], "int", 3) == 0 || strncmp(&code[i], "float", 5) == 0 || strncmp(&code[i], "char", 4) == 0) {
            printf("Data Type: %.*s\n", 3, &code[i]);
            i += 3;
        } else if (strncmp(&code[i], "for", 3) == 0 || strncmp(&code[i], "while", 5) == 0 || strncmp(&code[i], "do", 2) == 0) {
            printf("Loop: %.*s\n", 3, &code[i]);
            i += 3;
        } else {
            i++;
        }
    }

    return 0;
}
