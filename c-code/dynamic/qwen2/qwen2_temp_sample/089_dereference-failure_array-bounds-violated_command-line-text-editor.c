#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

void edit_text(char *text[], int *line_count) {
    char buffer[256];
    while (1) {
        printf("Enter line (or 'q' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == 'q') {
            break;
        }
        if (*line_count >= MAX_LINES) {
            printf("Error: Maximum number of lines reached.\n");
            continue;
        }
        text[*line_count] = strdup(buffer);
        (*line_count)++;
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
    char *text[MAX_LINES];
    int line_count = 0;

    edit_text(text, &line_count);

    display_text(text, line_count);

    free_memory(text, line_count);

    return 0;
}
