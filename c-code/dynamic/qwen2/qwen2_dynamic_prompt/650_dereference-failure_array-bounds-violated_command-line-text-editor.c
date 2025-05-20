#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void edit_text(char *text[], int line_count) {
    char buffer[256];
    while (1) {
        printf("Line %d: ", line_count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '\n') break;
        if (line_count >= MAX_LINES - 1) {
            printf("Error: Maximum number of lines reached.\n");
            continue;
        }
        text[line_count++] = strdup(buffer);
    }
}

void display_text(char *text[], int line_count) {
    for (int i = 0; i < line_count; i++) {
        printf("%s", text[i]);
    }
}

void free_memory(char *text[], int line_count) {
    for (int i = 0; i < line_count; i++) {
        free(text[i]);
    }
}

int main() {
    char *lines[MAX_LINES];
    int line_count = 0;

    printf("Welcome to SimpleTextEditor!\n");
    printf("Enter lines of text. Type an empty line to finish.\n");

    edit_text(lines, line_count);

    printf("\nYour text:\n");
    display_text(lines, line_count);

    free_memory(lines, line_count);

    return 0;
}
