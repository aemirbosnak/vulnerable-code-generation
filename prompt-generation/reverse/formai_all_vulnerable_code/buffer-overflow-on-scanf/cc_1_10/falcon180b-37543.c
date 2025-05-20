//Falcon-180B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

Line *read_lines_from_file(FILE *file, int *num_lines) {
    Line *lines = malloc(sizeof(Line) * MAX_NUM_LINES);
    int num_lines_read = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines_read >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: Reached maximum number of lines.\n");
            exit(1);
        }

        lines[num_lines_read].line = strdup(line);
        lines[num_lines_read].length = strlen(line);
        num_lines_read++;
    }

    *num_lines = num_lines_read;
    return lines;
}

void write_lines_to_file(FILE *file, Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s\n", lines[i].line);
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
    char input_file[100];
    char output_file[100];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        exit(1);
    }

    int num_lines;
    Line *lines = read_lines_from_file(input, &num_lines);

    reverse_lines(lines, num_lines);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        exit(1);
    }

    write_lines_to_file(output, lines, num_lines);

    fclose(input);
    fclose(output);

    printf("File successfully reversed and saved to %s.\n", output_file);

    return 0;
}