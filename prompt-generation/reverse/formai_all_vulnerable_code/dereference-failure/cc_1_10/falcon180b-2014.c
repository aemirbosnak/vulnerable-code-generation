//Falcon-180B DATASET v1.0 Category: File handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file and store it in a buffer
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            fprintf(stderr, "Line too long, truncating...\n");
            break;
        }
        line[i++] = c;
    }
    line[i] = '\0';
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to read all lines from a file and print them
void print_lines(FILE* file) {
    char* line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
        free(line);
    }
}

// Function to write a new line to a file
void append_line(FILE* file, char* line) {
    FILE* new_file = fopen("temp.txt", "w");
    if (new_file == NULL) {
        fprintf(stderr, "Error creating temp file\n");
        exit(1);
    }
    write_line(new_file, line);
    fclose(new_file);
    remove("original.txt");
    rename("temp.txt", "original.txt");
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE* file = fopen(argv[1], "r+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    print_lines(file);
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        append_line(file, input);
        print_lines(file);
    }
    fclose(file);
    return 0;
}