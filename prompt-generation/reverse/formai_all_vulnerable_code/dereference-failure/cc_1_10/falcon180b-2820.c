//Falcon-180B DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

typedef struct {
    char *text;
    int length;
} Line;

Line *read_lines(FILE *file) {
    Line *lines = (Line *) malloc(MAX_LINES * sizeof(Line));
    int num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].text = strdup(line);
        lines[num_lines].length = strlen(line);
        num_lines++;
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

void sort_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (lines[j].length < lines[i].length) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    Line *lines = read_lines(input_file);
    int num_lines = 0;

    while (fgetc(input_file)!= EOF) {
        num_lines++;
    }

    fclose(input_file);

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error reopening input file\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    reverse_lines(lines, num_lines);
    sort_lines(lines, num_lines);

    write_lines(lines, num_lines, output_file);

    fclose(input_file);
    fclose(output_file);

    free(lines);

    return 0;
}