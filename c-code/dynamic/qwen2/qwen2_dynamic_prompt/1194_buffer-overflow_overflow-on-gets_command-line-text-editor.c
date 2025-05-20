#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128

void edit_text(char *text) {
    char line[MAX_LINE_LENGTH];
    while (1) {
        printf("Enter a line (or 'exit' to quit): ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        if (line[0] == '\n') {
            continue;
        }
        if (strcmp(line, "exit\n") == 0) {
            break;
        }
        // Vulnerability: Using gets() instead of fgets()
        gets(text);
        strcat(text, line);
    }
}

int main() {
    char *text = (char *)malloc(MAX_LINE_LENGTH);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(text, "Initial text\n");

    printf("Welcome to the Text Editor!\n");
    edit_text(text);

    printf("Final text:\n%s", text);

    free(text);
    return 0;
}
