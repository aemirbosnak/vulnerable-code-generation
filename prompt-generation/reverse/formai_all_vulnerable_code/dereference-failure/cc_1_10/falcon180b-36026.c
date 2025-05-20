//Falcon-180B DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    int length;
} Line;

Line* read_lines(FILE* file, int* num_lines) {
    Line* lines = (Line*) malloc(MAX_NUM_LINES * sizeof(Line));
    if (!lines) {
        printf("Error: Could not allocate memory for lines.\n");
        exit(1);
    }

    int num_lines_read = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines_read >= MAX_NUM_LINES) {
            printf("Error: Maximum number of lines exceeded.\n");
            exit(1);
        }

        lines[num_lines_read].length = strlen(line);
        strcpy(lines[num_lines_read].line, line);
        num_lines_read++;
    }

    *num_lines = num_lines_read;
    return lines;
}

void write_lines(Line* lines, int num_lines, FILE* file) {
    for (int i = 0; i < num_lines; i++) {
        fwrite(lines[i].line, lines[i].length, 1, file);
        fwrite("\n", 1, 1, file);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (!input_file) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (!output_file) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    int num_lines;
    Line* lines = read_lines(input_file, &num_lines);

    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].line, "error")!= NULL) {
            printf("Line %d contains the word 'error'.\n", i + 1);
        }
    }

    write_lines(lines, num_lines, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}