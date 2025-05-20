//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

// Struct to store line information
typedef struct {
    char line[MAX_LINE_LENGTH];
    int line_number;
} Line;

// Function to read in lines from a file
void read_lines(FILE *file, Line *lines, int *num_lines) {
    char ch;
    int i = 0;
    while (fscanf(file, "%c", &ch)!= EOF) {
        if (i >= *num_lines - 1) {
            // Reallocate memory for more lines
            *num_lines += 100;
            lines = realloc(lines, sizeof(Line) * *num_lines);
        }
        if (ch == '\n') {
            // Increment line number for each new line
            lines[i].line_number++;
        }
        strncat(lines[i].line, &ch, 1);
        i++;
    }
}

// Function to print out line information
void print_lines(Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_number, lines[i].line);
    }
}

// Function to search for a pattern in the lines
void search_pattern(Line *lines, int num_lines, char *pattern) {
    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i].line, pattern)!= NULL) {
            printf("Line %d contains the pattern '%s'.\n", lines[i].line_number, pattern);
        }
    }
}

int main() {
    FILE *file;
    Line *lines = NULL;
    int num_lines = 0;

    // Open file for reading
    file = fopen("example.log", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in lines from file
    read_lines(file, lines, &num_lines);

    // Print out line information
    printf("Contents of example.log:\n");
    print_lines(lines, num_lines);

    // Search for a pattern in the lines
    char pattern[] = "error";
    search_pattern(lines, num_lines, pattern);

    // Free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    fclose(file);
    return 0;
}