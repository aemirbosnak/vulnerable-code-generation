#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Line {
    char *text;
    struct Line *next;
} Line;

void add_line(Line **lines, const char *line) {
    Line *new_line = (Line *) malloc(sizeof(Line));
    new_line->text = strdup(line);
    new_line->next = *lines;
    *lines = new_line;
}

void print_lines(Line *lines) {
    while (lines) {
        printf("%s\n", lines->text);
        lines = lines->next;
    }
}

int main(int argc, char **argv) {
    Line *lines = NULL;

    if (argc <= 1) {
        printf("Usage: %s [lines]...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        add_line(&lines, argv[i]);
    }

    print_lines(lines);

    Line *current = lines;
    while (current != NULL) {
        Line *next = current->next;
        free(current->text);
        free(current);
        current = next;
    }

    return 0;
}
