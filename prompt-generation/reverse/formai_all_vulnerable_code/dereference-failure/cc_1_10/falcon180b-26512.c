//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to print error message and exit the program
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        error("Failed to read line from file");
    }
    return strdup(line);
}

// Function to write a line to a file
int write_line(FILE* file, const char* line) {
    if (fputs(line, file) == EOF) {
        error("Failed to write line to file");
    }
    if (fputc('\n', file) == EOF) {
        error("Failed to write line to file");
    }
    return 0;
}

// Function to reverse the order of lines in a file
int reverse_file(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        error("Failed to open input file");
    }
    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        error("Failed to open output file");
    }

    char* line = NULL;
    while ((line = read_line(input))!= NULL) {
        if (write_line(output, line)!= 0) {
            error("Failed to write line to output file");
        }
    }

    if (fclose(input)!= 0) {
        error("Failed to close input file");
    }
    if (fclose(output)!= 0) {
        error("Failed to close output file");
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        error("Usage:./program input_file output_file");
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];

    if (reverse_file(input_file, output_file)!= 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}