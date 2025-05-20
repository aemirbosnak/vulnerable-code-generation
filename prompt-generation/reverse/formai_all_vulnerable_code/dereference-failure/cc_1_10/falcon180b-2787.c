//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum line length
#define MAX_NUM_LINES 100000 // Maximum number of lines

// Function prototypes
void read_file(FILE *file, char **lines);
void write_file(FILE *file, char **lines);
void free_lines(char **lines);

int main() {
    FILE *input_file, *output_file;
    char **lines;

    // Open the input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read the lines from the input file
    read_file(input_file, &lines);

    // Open the output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write the lines to the output file
    write_file(output_file, lines);

    // Close the files and free the memory used by the lines
    fclose(input_file);
    fclose(output_file);
    free_lines(lines);

    return 0;
}

// Reads the lines from the input file
void read_file(FILE *file, char **lines) {
    int line_num = 0;
    char line[MAX_LINE_LENGTH];

    // Allocate memory for the lines
    lines[line_num] = malloc(MAX_LINE_LENGTH * sizeof(char));

    // Read the lines from the file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Check if we need to allocate more memory
        if (line_num == MAX_NUM_LINES - 1) {
            printf("Error: Maximum number of lines reached.\n");
            exit(1);
        }

        // Copy the line to the lines array
        strcpy(lines[++line_num], line);
    }
}

// Writes the lines to the output file
void write_file(FILE *file, char **lines) {
    int line_num = 0;

    // Write the lines to the file
    while (lines[line_num]!= NULL) {
        fprintf(file, "%s", lines[++line_num]);
    }
}

// Frees the memory used by the lines
void free_lines(char **lines) {
    int i;

    for (i = 0; lines[i]!= NULL; ++i) {
        free(lines[i]);
    }
}