//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

// Function to compare two strings
int strcmp(const char* str1, const char* str2) {
    while (*str1 && *str2 && tolower(*str1) == tolower(*str2)) {
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, file);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, const char* line) {
    fprintf(file, "%s\n", line);
}

// Function to synchronize two files
void synchronize_files(const char* file1, const char* file2) {
    FILE* file1_ptr = fopen(file1, "r");
    FILE* file2_ptr = fopen(file2, "r");

    if (file1_ptr == NULL || file2_ptr == NULL) {
        printf("Error: Could not open one or both files.\n");
        exit(1);
    }

    char* line1 = NULL;
    char* line2 = NULL;

    while ((line1 = read_line(file1_ptr))!= NULL || (line2 = read_line(file2_ptr))!= NULL) {
        int cmp_result = strcmp(line1, line2);

        if (cmp_result < 0) {
            write_line(file2_ptr, line1);
        } else if (cmp_result > 0) {
            write_line(file1_ptr, line2);
        }

        free(line1);
        free(line2);
        line1 = read_line(file1_ptr);
        line2 = read_line(file2_ptr);
    }

    fclose(file1_ptr);
    fclose(file2_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    synchronize_files(argv[1], argv[2]);

    return 0;
}