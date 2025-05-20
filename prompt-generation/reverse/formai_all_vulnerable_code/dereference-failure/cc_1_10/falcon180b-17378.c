//Falcon-180B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    int line_number;
} Line;

void read_file(char* filename, Line lines[], int* num_lines) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    *num_lines = 0;
    while (fgets(lines[*num_lines].line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[*num_lines].line_number = *num_lines;
        (*num_lines)++;
    }

    fclose(file);
}

void write_file(char* filename, Line lines[], int num_lines) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%d: %s", lines[i].line_number, lines[i].line);
    }

    fclose(file);
}

void reverse_lines(Line lines[], int num_lines) {
    for (int i = 0; i < num_lines / 2; i++) {
        Line temp = lines[i];
        lines[i] = lines[num_lines - i - 1];
        lines[num_lines - i - 1] = temp;
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char input_filename[100];
    char output_filename[100];
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    read_file(input_filename, lines, &num_lines);
    reverse_lines(lines, num_lines);
    write_file(output_filename, lines, num_lines);

    printf("Done!\n");
    return 0;
}