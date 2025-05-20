//Falcon-180B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error reading line from file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, const char* line) {
    if (fputs(line, file) == EOF) {
        fprintf(stderr, "Error writing line to file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Function to process a line of text
void process_line(const char* line) {
    printf("Processing line: %s\n", line);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char* line = read_line(input_file);
    while (line!= NULL) {
        process_line(line);
        write_line(output_file, line);
        line = read_line(input_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}