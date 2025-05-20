//Falcon-180B DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_SIZE 100000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error reading line from file\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to open a file for reading and writing
FILE* open_file(char* filename, char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    return file;
}

// Function to close a file
void close_file(FILE* file) {
    fclose(file);
}

// Function to count the number of lines in a file
int count_lines(FILE* file) {
    int count = 0;
    char* line = read_line(file);
    while (line!= NULL) {
        count++;
        line = read_line(file);
    }
    return count;
}

// Function to count the number of words in a line
int count_words(char* line) {
    int count = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    // Open the file for reading and writing
    FILE* file = open_file("example.txt", "r+");

    // Count the number of lines in the file
    int line_count = count_lines(file);
    printf("The file contains %d lines\n", line_count);

    // Loop through each line in the file
    int i;
    for (i = 0; i < line_count; i++) {
        // Read the line from the file
        char* line = read_line(file);

        // Count the number of words in the line
        int word_count = count_words(line);
        printf("Line %d contains %d words\n", i + 1, word_count);

        // Write the line back to the file
        write_line(file, line);
    }

    // Close the file
    close_file(file);

    return 0;
}