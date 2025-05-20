//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *result = fgets(line, MAX_LINE_LENGTH, file);
    if (result == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line to a file
void write_line(FILE *file, char *line) {
    fprintf(file, "%s", line);
}

// Function to count the number of lines in a file
int count_lines(FILE *file) {
    int count = 0;
    char *line = read_line(file);
    while (line!= NULL) {
        count++;
        line = read_line(file);
    }
    return count;
}

// Function to reverse the order of lines in a file
void reverse_file(FILE *input_file, FILE *output_file) {
    char *line;
    while ((line = read_line(input_file))!= NULL) {
        write_line(output_file, line);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    int num_lines;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Count the number of lines in the input file
    num_lines = count_lines(input_file);

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Reverse the order of lines in the input file and write to output file
    reverse_file(input_file, output_file);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File reversed successfully.\n");
    return 0;
}