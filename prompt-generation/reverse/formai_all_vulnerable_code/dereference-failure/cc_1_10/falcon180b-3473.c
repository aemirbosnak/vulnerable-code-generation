//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to compare two strings
int compare_strings(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

// Function to sort an array of strings
void sort_strings(char **array, int count) {
    qsort(array, count, sizeof(char *), compare_strings);
}

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Failed to read line from file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line to a file
void write_line(FILE *file, const char *line) {
    fprintf(file, "%s", line);
}

// Function to synchronize two files
void synchronize_files(const char *file1_path, const char *file2_path) {
    FILE *file1 = fopen(file1_path, "r");
    if (file1 == NULL) {
        fprintf(stderr, "Error: Failed to open file 1.\n");
        exit(1);
    }

    FILE *file2 = fopen(file2_path, "r");
    if (file2 == NULL) {
        fprintf(stderr, "Error: Failed to open file 2.\n");
        exit(1);
    }

    char *line1 = read_line(file1);
    char *line2 = read_line(file2);

    while (line1!= NULL || line2!= NULL) {
        int cmp = compare_strings(line1, line2);
        if (cmp < 0) {
            // Line 1 is earlier, write it to file 2
            write_line(file2, line1);
            line1 = read_line(file1);
        } else if (cmp > 0) {
            // Line 2 is earlier, write it to file 1
            write_line(file1, line2);
            line2 = read_line(file2);
        } else {
            // Lines are the same, skip them
            line1 = read_line(file1);
            line2 = read_line(file2);
        }
    }

    fclose(file1);
    fclose(file2);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}