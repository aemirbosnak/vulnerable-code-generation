//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(FILE *file) {
    Line *lines = NULL;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[--length] = '\0';
        }
        lines = realloc(lines, sizeof(Line) * (line_number + 1));
        lines[line_number - 1].text = strdup(line);
        lines[line_number - 1].length = length;
    }

    return lines;
}

void free_lines(Line *lines, int count) {
    for (int i = 0; i < count; i++) {
        free(lines[i].text);
    }
    free(lines);
}

void indent(int level, FILE *file) {
    for (int i = 0; i < level * 4; i++) {
        fputc(' ', file);
    }
}

void write_html(Line *lines, int line_number, FILE *file) {
    for (int i = 0; i < line_number; i++) {
        if (lines[i].text[0] == '<') {
            fprintf(file, "%s", lines[i].text);
        } else {
            indent(4, file);
            fprintf(file, "%s", lines[i].text);
        }
        fprintf(file, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    Line *lines = read_file(input_file);
    if (lines == NULL) {
        fprintf(stderr, "Error reading input file\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        free_lines(lines, 0);
        return 1;
    }

    write_html(lines, lines->length, output_file);

    free_lines(lines, lines->length);
    fclose(input_file);
    fclose(output_file);

    return 0;
}