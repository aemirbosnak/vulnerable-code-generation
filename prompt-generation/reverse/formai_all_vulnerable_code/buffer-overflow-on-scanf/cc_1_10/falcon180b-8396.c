//Falcon-180B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <limits.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
} File;

int count_lines(File *file) {
    int count = 0;
    char c;
    rewind(file->file);
    while ((c = fgetc(file->file))!= EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

void print_file(File *file) {
    printf("File: %s\n", file->filename);
    printf("Number of Lines: %d\n", count_lines(file));
}

int main() {
    int i, j, k;
    char filename[100];
    char buffer[BUFFER_SIZE];
    File file;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    file.filename = filename;
    file.file = fopen(filename, "r");
    if (file.file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file into buffer
    i = 0;
    while ((k = fread(buffer + i, 1, BUFFER_SIZE - i, file.file))!= 0) {
        i += k;
    }
    buffer[i] = '\0';

    // Print file to console
    print_file(&file);

    // Close file
    fclose(file.file);

    return 0;
}