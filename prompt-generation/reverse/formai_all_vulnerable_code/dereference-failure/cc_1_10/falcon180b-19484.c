//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line
#define MAX_LINE_LENGTH 100

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    if (line == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error: Failed to read line from file!\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, const char* line) {
    if (fputs(line, file) == EOF) {
        printf("Error: Failed to write line to file!\n");
        exit(1);
    }
}

// Function to count the number of lines in the file
int count_lines(FILE* file) {
    int count = 0;
    char* line;
    while ((line = read_line(file))!= NULL) {
        count++;
        free(line);
    }
    return count;
}

// Function to reverse the order of lines in the file
void reverse_lines(FILE* file) {
    char* line;
    while ((line = read_line(file))!= NULL) {
        write_line(file, line);
        free(line);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file!\n");
        exit(1);
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Failed to open output file!\n");
        exit(1);
    }

    int line_count = count_lines(input_file);
    printf("Reversing %d lines...\n", line_count);

    reverse_lines(input_file);
    reverse_lines(output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}