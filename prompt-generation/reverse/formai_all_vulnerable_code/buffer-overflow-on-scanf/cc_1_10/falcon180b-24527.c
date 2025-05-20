//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_LENGTH 1000

// Function to extract metadata from a given file
void extract_metadata(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Extract file size
    rewind(file);
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Extract number of lines
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;
    }

    // Extract average line length
    rewind(file);
    int total_line_length = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        total_line_length += strlen(line);
    }
    double avg_line_length = (double)total_line_length / line_number;

    // Print extracted metadata
    printf("File size: %ld bytes\n", file_size);
    printf("Number of lines: %d\n", line_number);
    printf("Average line length: %.2f characters\n", avg_line_length);
}

int main() {
    char filename[MAX_FILE_SIZE];
    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Extract metadata from the file
    extract_metadata(file);

    // Close the file
    fclose(file);

    return 0;
}