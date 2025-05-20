#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void analyze_code(char *code) {
    char *token;
    int loop_count = 0;

    token = strtok(code, " ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0) {
            printf("Datatype: %s\n", token);
        } else if (strcmp(token, "for") == 0 || strcmp(token, "while") == 0 || strcmp(token, "do") == 0) {
            printf("Loop structure: %s\n", token);
            loop_count++;
        }
        token = strtok(NULL, " ");
    }

    if (loop_count > 3) {
        printf("Cyclomatic complexity is high.\n");
    }
}

int main() {
    char code[100];

    printf("Enter C code: ");
    gets(code); // Vulnerable function

    analyze_code(code);

    return 0;
}
