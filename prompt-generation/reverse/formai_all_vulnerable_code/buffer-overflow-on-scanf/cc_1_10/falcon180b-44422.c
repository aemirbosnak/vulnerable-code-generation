//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        // Error reading line
        printf("Error reading line\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to read a file and print its contents
void read_file(FILE* file) {
    char* line = NULL;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }
}

// Function to write to a file
void write_to_file(FILE* file) {
    char* input = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    printf("Enter text to write to file: ");
    fgets(input, MAX_LINE_SIZE, stdin);
    write_line(file, input);
}

// Function to append to a file
void append_to_file(FILE* file) {
    char* input = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    printf("Enter text to append to file: ");
    fgets(input, MAX_LINE_SIZE, stdin);
    fprintf(file, "%s", input);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File not found
        printf("File not found\n");
        exit(1);
    }

    printf("Contents of file:\n");
    read_file(file);

    fclose(file);

    file = fopen(filename, "a");
    if (file == NULL) {
        // Error opening file
        printf("Error opening file\n");
        exit(1);
    }

    printf("Append to file:\n");
    append_to_file(file);

    fclose(file);

    return 0;
}