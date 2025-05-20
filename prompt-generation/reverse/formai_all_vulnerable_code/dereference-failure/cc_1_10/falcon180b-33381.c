//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

// Function to read a line from the file
char* readLine(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        fprintf(stderr, "Error reading line from file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void writeLine(FILE* file, const char* line) {
    if (fputs(line, file) == EOF) {
        fprintf(stderr, "Error writing line to file.\n");
        exit(1);
    }
}

// Function to read all lines from a file and store them in an array
void readLines(FILE* file, char** lines, int* numLines) {
    *numLines = 0;
    while (fgets(lines[*numLines], MAX_LINE_SIZE, file)!= NULL) {
        (*numLines)++;
    }
}

// Function to write all lines to a file
void writeLines(FILE* file, const char** lines, int numLines) {
    for (int i = 0; i < numLines; i++) {
        writeLine(file, lines[i]);
    }
}

// Function to reverse the order of lines in a file
void reverseLines(FILE* file) {
    char* line = NULL;
    char** lines = NULL;
    int numLines = 0;

    // Read all lines from the file
    readLines(file, &line, &numLines);

    // Allocate memory for the lines array
    lines = malloc(numLines * sizeof(char*));

    // Copy the lines to the array
    for (int i = 0; i < numLines; i++) {
        lines[numLines - i - 1] = line;
        line = readLine(file);
    }

    // Write the reversed lines to the file
    writeLines(file, lines, numLines);

    // Free the lines array
    for (int i = 0; i < numLines; i++) {
        free(lines[i]);
    }
    free(lines);
}

int main() {
    FILE* file;
    char* filename = "example.txt";

    // Open the file for reading and writing
    if ((file = fopen(filename, "r+")) == NULL) {
        fprintf(stderr, "Error opening file %s.\n", filename);
        return 1;
    }

    // Reverse the order of lines in the file
    reverseLines(file);

    // Close the file
    if (fclose(file)!= 0) {
        fprintf(stderr, "Error closing file %s.\n", filename);
        return 1;
    }

    return 0;
}