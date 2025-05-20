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

void append_line(Line *lines, const char *line) {
    lines->text = realloc(lines->text, (lines->length + 1) * sizeof(char));
    if (!lines->text) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    lines->text[lines->length++] = '\n';
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

    Line lines = {NULL, 0};
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        append_line(&lines, buffer);
    }

    fclose(file);

    // Integer overflow vulnerability
    int num_lines = lines.length / 10; // This can cause an overflow if lines.length is large enough

    printf("Number of lines: %d\n", num_lines);

    free(lines.text);

    return 0;
}
