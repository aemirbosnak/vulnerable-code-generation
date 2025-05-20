//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the input file
char* read_line(FILE* input_file) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, input_file) == NULL) {
        printf("Error reading line\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the output file
void write_line(FILE* output_file, char* line) {
    fprintf(output_file, "%s", line);
}

// Function to recover data from a corrupted file
void recover_data(FILE* input_file, FILE* output_file) {
    char* line;
    int line_number = 1;

    // Read the first line
    line = read_line(input_file);
    write_line(output_file, line);

    // Read the rest of the lines
    while ((line = read_line(input_file))!= NULL) {
        line_number++;

        // Check if the line is corrupted
        if (strlen(line) < 5) {
            printf("Line %d is corrupted\n", line_number);
            continue;
        }

        // Write the line to the output file
        write_line(output_file, line);
    }
}

int main() {
    FILE* input_file;
    FILE* output_file;

    // Open the input and output files
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Recover data from the input file
    recover_data(input_file, output_file);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}