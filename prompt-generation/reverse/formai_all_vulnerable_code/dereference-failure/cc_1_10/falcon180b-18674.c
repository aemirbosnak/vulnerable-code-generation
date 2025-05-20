//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_lines(FILE *file) {
    Line *lines = malloc(MAX_LINES * sizeof(Line));
    int num_lines = 0;

    while (fgets(lines[num_lines].text, MAX_LINES, file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].text);
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

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Line *lines = read_lines(input_file);
    int num_lines = 0;

    while (lines[num_lines].text!= NULL) {
        num_lines++;
    }

    reverse_lines(lines, num_lines);

    write_lines(lines, num_lines, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}