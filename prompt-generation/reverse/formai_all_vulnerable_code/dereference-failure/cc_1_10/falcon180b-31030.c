//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_length;
} Line;

Line *read_file(FILE *file, int *num_lines) {
    Line *lines = malloc(MAX_NUM_LINES * sizeof(Line));
    int current_line = 0;

    while (fgets(lines[current_line].line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[current_line].line_length = strlen(lines[current_line].line);
        current_line++;
    }

    *num_lines = current_line;
    return lines;
}

void write_file(FILE *file, Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].line);
    }
}

void reverse_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines / 2; i++) {
        Line temp = lines[i];
        lines[i] = lines[num_lines - 1 - i];
        lines[num_lines - 1 - i] = temp;
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(1);
    }

    int num_lines;
    Line *lines = read_file(input_file, &num_lines);

    reverse_lines(lines, num_lines);

    write_file(output_file, lines, num_lines);

    fclose(input_file);
    fclose(output_file);

    return 0;
}