#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_brackets(char *str) {
    int depth = 0, i = 0;
    char *buf = NULL, *token = NULL;

    if (!str) return;

    buf = malloc(strlen(str) + 1);
    if (!buf) return;

    token = strtok(str, "{}[]()");
    while (token) {
        if (depth > 0 && *(token) == '}') depth--;
        else if (*(token) == '{') depth++;

        if (depth > 0) {
            strcat(buf, token);
            i++;
        }

        token = strtok(NULL, "{}[]()");
    }

    free(buf); // Use-after-free vulnerability: buf is accessed later in the if condition below

    if (depth > 0) printf("Unbalanced brackets found.\n");
    else printf("Balanced brackets found.\n");

    if (i > 0) printf("Tokens found: %s\n", buf);
}

int main() {
    char str[] = "{{[()()]}}";
    parse_brackets(str);
    printf("Accessing freed memory...\n");
    return 0;
}
