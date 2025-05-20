//Falcon-180B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

// Struct to hold line information
typedef struct {
    char *line;
    int length;
} Line;

// Function to read a file and store its lines in an array of Line structs
void read_file(char *filename, Line *lines, int *num_lines) {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    int line_num = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    *num_lines = 0;
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        lines[*num_lines].line = strdup(buffer);
        lines[*num_lines].length = strlen(buffer);
        (*num_lines)++;
    }

    fclose(file);
}

// Function to print the lines of a file
void print_file(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i+1, lines[i].line);
    }
}

// Function to reverse the order of the lines in a file
void reverse_file(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines/2; i++) {
        Line temp = lines[i];
        lines[i] = lines[num_lines-i-1];
        lines[num_lines-i-1] = temp;
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    read_file(filename, lines, &num_lines);
    printf("Original file:\n");
    print_file(lines, num_lines);

    reverse_file(lines, num_lines);
    printf("\nReversed file:\n");
    print_file(lines, num_lines);

    return 0;
}