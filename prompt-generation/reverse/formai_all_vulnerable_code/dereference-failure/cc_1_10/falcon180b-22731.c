//Falcon-180B DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_lines(FILE *file) {
    Line *lines = NULL;
    int num_lines = 0;
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: Too many lines in file.\n");
            exit(1);
        }
        Line *line = malloc(sizeof(Line));
        line->text = strdup(buffer);
        line->length = strlen(buffer);
        lines = realloc(lines, sizeof(Line) * ++num_lines);
        lines[num_lines - 1] = *line;
    }

    return lines;
}

void write_lines(Line *lines, int num_lines, FILE *file) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].text);
    }
}

void reverse_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines / 2; i++) {
        Line temp = lines[i];
        lines[i] = lines[num_lines - i - 1];
        lines[num_lines - i - 1] = temp;
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    Line *lines = read_lines(input_file);
    fclose(input_file);

    reverse_lines(lines, lines->length);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        return 1;
    }

    write_lines(lines, lines->length, output_file);
    fclose(output_file);

    free(lines);

    return 0;
}