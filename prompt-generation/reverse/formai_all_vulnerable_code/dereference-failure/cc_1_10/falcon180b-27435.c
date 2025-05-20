//Falcon-180B DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file and store it in a buffer
char* read_line(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char* buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (buffer == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fgets(line, MAX_LINE_LENGTH, file);
    // Remove newline character from the end of the line
    line[strcspn(line, "\n")] = '\0';

    strcpy(buffer, line);
    return buffer;
}

// Function to write a buffer to the file
void write_buffer(FILE* file, char* buffer) {
    fprintf(file, "%s", buffer);
}

// Function to read a file and reverse the order of the lines
void reverse_file(FILE* input_file, FILE* output_file) {
    char* buffer;
    while ((buffer = read_line(input_file))!= NULL) {
        write_buffer(output_file, buffer);
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    reverse_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File reversed successfully!\n");
    return 0;
}