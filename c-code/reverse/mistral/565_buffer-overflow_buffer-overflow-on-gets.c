#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

void find_datatypes(char *str) {
    char *tokens[10];
    char delimiters[] = " \t\n\r,;";
    int token_count = 0;

    char *token = strtok(str, delimiters);
    while (token != NULL) {
        if (!strcmp(token, "int") || !strcmp(token, "char") || !strcmp(token, "float") || !strcmp(token, "double")) {
            printf("Data Type: %s\n", token);
        }
        token = strtok(NULL, delimiters);
        token_count++;
    }
}

void find_loops(char *str) {
    char *tokens[10];
    char delimiters[] = " \t\n\r,;";
    int token_count = 0;

    char *token = strtok(str, delimiters);
    while (token != NULL) {
        if (!strcmp(token, "for") || !strcmp(token, "while")) {
            printf("Loop Construct: %s\n", token);
        }
        token = strtok(NULL, delimiters);
        token_count++;
    }
}

int main() {
    char code[MAX_LINE];
    printf("Enter C code:\n");
    fgets(code, MAX_LINE, stdin);

    find_datatypes(code);
    find_loops(code);

    return 0;
}
