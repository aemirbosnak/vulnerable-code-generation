//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    size_t length;
} Line;

Line *lines = NULL;
size_t num_lines = 0;

void add_line(const char *line) {
    if (num_lines == MAX_NUM_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        exit(1);
    }

    size_t length = strlen(line);
    if (length > MAX_LINE_LENGTH) {
        printf("Error: Line too long.\n");
        exit(1);
    }

    Line *new_line = malloc(sizeof(Line));
    if (new_line == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    new_line->line = strdup(line);
    new_line->length = length;

    lines = realloc(lines, sizeof(Line) * ++num_lines);
    lines[num_lines - 1] = *new_line;
}

void print_lines() {
    if (num_lines == 0) {
        printf("No lines to print.\n");
        return;
    }

    for (size_t i = 0; i < num_lines; i++) {
        printf("%zu: %s\n", i + 1, lines[i].line);
    }
}

int main() {
    char input[MAX_LINE_LENGTH];

    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(input);
    }

    print_lines();

    free(lines);
    return 0;
}