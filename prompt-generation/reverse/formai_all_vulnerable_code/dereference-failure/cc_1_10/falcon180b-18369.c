//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256
#define MAX_NUM_FILES 1000

// Function to compare two strings (case insensitive)
int compare_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    getline(&line, &len, file)!= -1;

    if (line == NULL) {
        line = malloc(1);
        line[0] = '\0';
    }

    return line;
}

// Function to write a line to a file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s\n", line);
}

// Function to synchronize two files
void synchronize_files(char* file1, char* file2) {
    FILE* file1_ptr = fopen(file1, "r");
    FILE* file2_ptr = fopen(file2, "r");

    if (file1_ptr == NULL || file2_ptr == NULL) {
        printf("Error: One or both files could not be opened.\n");
        exit(1);
    }

    char* line1 = read_line(file1_ptr);
    char* line2 = read_line(file2_ptr);

    while (line1!= NULL || line2!= NULL) {
        if (compare_strings(line1, line2)) {
            write_line(file2_ptr, line1);
            line2 = read_line(file2_ptr);
        } else {
            write_line(file1_ptr, line2);
            line1 = read_line(file1_ptr);
        }
    }

    fclose(file1_ptr);
    fclose(file2_ptr);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    char* file1 = argv[1];
    char* file2 = argv[2];

    synchronize_files(file1, file2);

    return 0;
}