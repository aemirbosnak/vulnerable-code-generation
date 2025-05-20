//Falcon-180B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    size_t length;
} Line;

typedef struct {
    Line *lines;
    size_t num_lines;
    size_t capacity;
} Lines;

Lines *lines_create() {
    Lines *lines = malloc(sizeof(Lines));
    if (lines == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for lines.\n");
        exit(EXIT_FAILURE);
    }
    lines->lines = NULL;
    lines->num_lines = 0;
    lines->capacity = 0;
    return lines;
}

void lines_destroy(Lines *lines) {
    if (lines == NULL) {
        return;
    }
    for (size_t i = 0; i < lines->num_lines; i++) {
        free(lines->lines[i].line);
    }
    free(lines->lines);
    free(lines);
}

void lines_clear(Lines *lines) {
    if (lines == NULL) {
        return;
    }
    for (size_t i = 0; i < lines->num_lines; i++) {
        free(lines->lines[i].line);
    }
    lines->num_lines = 0;
}

void lines_append(Lines *lines, const char *str) {
    if (lines == NULL) {
        return;
    }
    if (lines->num_lines >= lines->capacity) {
        lines->capacity += MAX_NUM_LINES;
        lines->lines = realloc(lines->lines, lines->capacity * sizeof(Line));
        if (lines->lines == NULL) {
            fprintf(stderr, "Error: Failed to reallocate memory for lines.\n");
            exit(EXIT_FAILURE);
        }
    }
    size_t str_len = strlen(str);
    if (str_len > MAX_LINE_LENGTH) {
        fprintf(stderr, "Error: Line is too long.\n");
        exit(EXIT_FAILURE);
    }
    lines->lines[lines->num_lines].line = malloc(str_len + 1);
    if (lines->lines[lines->num_lines].line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for line.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(lines->lines[lines->num_lines].line, str);
    lines->lines[lines->num_lines].length = str_len;
    lines->num_lines++;
}

void lines_print(const Lines *lines) {
    if (lines == NULL || lines->num_lines == 0) {
        return;
    }
    for (size_t i = 0; i < lines->num_lines; i++) {
        printf("%s\n", lines->lines[i].line);
    }
}

int main() {
    Lines *lines = lines_create();
    lines_append(lines, "Hello, world!");
    lines_append(lines, "This is a test.");
    lines_print(lines);
    lines_destroy(lines);
    return 0;
}