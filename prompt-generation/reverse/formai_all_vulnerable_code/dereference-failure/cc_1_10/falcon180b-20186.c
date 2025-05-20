//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to extract metadata from a given file
void extract_metadata(FILE *file) {
    char line[MAX_LINE_SIZE];
    char *filename = NULL;
    char *file_extension = NULL;
    char *file_size = NULL;
    char *date_created = NULL;
    char *date_modified = NULL;

    // Read the first line to get the filename
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: Cannot read file.\n");
        exit(1);
    }
    filename = strtok(line, "\n");

    // Extract file extension
    file_extension = strrchr(filename, '.');
    if (file_extension == NULL) {
        printf("Error: Invalid file extension.\n");
        exit(1);
    }

    // Extract file size
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: Cannot read file.\n");
        exit(1);
    }
    file_size = strtok(line, "\n");

    // Extract date created
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: Cannot read file.\n");
        exit(1);
    }
    date_created = strtok(line, "\n");

    // Extract date modified
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error: Cannot read file.\n");
        exit(1);
    }
    date_modified = strtok(line, "\n");

    // Print extracted metadata
    printf("Filename: %s\n", filename);
    printf("File extension: %s\n", file_extension);
    printf("File size: %s bytes\n", file_size);
    printf("Date created: %s\n", date_created);
    printf("Date modified: %s\n", date_modified);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Open the file for reading
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    // Extract metadata from the file
    extract_metadata(file);

    // Close the file
    fclose(file);

    return 0;
}