#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char *text;
    int length;
} Line;

void add_line(Line *lines, const char *line) {
    if (lines->length >= MAX_LINES) return;
    lines->text[lines->length] = strdup(line);
    lines->length++;
}

void print_lines(Line *lines) {
    for (int i = 0; i < lines->length; i++) {
        printf("%s\n", lines->text[i]);
    }
}

void free_lines(Line *lines) {
    for (int i = 0; i < lines->length; i++) {
        free(lines->text[i]);
    }
    free(lines->text);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    Line lines = { .text = malloc(MAX_LINES * sizeof(char*)), .length = 0 };
    if (!lines.text) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(&lines, buffer);
    }

    fclose(file);

    print_lines(&lines);

    free_lines(&lines);

    // Dereference failure example
    char *ptr = NULL;
    printf("%s\n", ptr); // This will cause a segmentation fault

    return 0;
}
