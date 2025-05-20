#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *text, int line_number, const char *new_line) {
    if (line_number < 0) return;
    size_t len = strlen(text);
    if (len + strlen(new_line) >= MAX_LINE_LENGTH - 1) return;

    // Simulate inserting new line at specified position
    memmove(text + line_number * MAX_LINE_LENGTH, text + line_number * MAX_LINE_LENGTH + strlen(new_line), len - line_number * MAX_LINE_LENGTH);
    strcpy(text + line_number * MAX_LINE_LENGTH, new_line);

    // Add null terminator at the end
    text[len + strlen(new_line)] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <line_number> <new_line>\n", argv[0]);
        return 1;
    }

    int line_number = atoi(argv[1]);
    const char *new_line = argv[2];

    char *text = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!text) {
        perror("Failed to allocate memory");
        return 1;
    }
    strcpy(text, "");

    edit_text(text, line_number, new_line);

    printf("Updated text:\n%s\n", text);

    free(text);
    return 0;
}
