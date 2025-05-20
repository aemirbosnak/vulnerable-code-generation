//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1024
#define MAX_LINE_SIZE 2048

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_SIZE];
    int line_num = 0;

    // Extract file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    // Extract file type
    char file_type[MAX_FILE_NAME];
    strcpy(file_type, "unknown");
    if (filename) {
        int dot_pos = strlen(filename) - 1;
        while (dot_pos > 0 && filename[dot_pos]!= '.') {
            dot_pos--;
        }
        if (dot_pos > 0) {
            strcpy(file_type, &filename[dot_pos + 1]);
        }
    }

    // Extract line count
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_num++;
    }
    rewind(file);

    printf("File name: %s\n", filename? filename : "unknown");
    printf("File type: %s\n", file_type);
    printf("File size: %d bytes\n", file_size);
    printf("Line count: %d\n", line_num);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char filename[MAX_FILE_NAME];
    strcpy(filename, argv[1]);
    extract_metadata(file, filename);

    fclose(file);
    return 0;
}