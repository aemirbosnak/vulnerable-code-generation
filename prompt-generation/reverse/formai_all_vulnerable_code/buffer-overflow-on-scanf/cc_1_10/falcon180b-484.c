//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Struct for holding metadata information
typedef struct {
    char *filename;
    int filesize;
    char *filetype;
    char *creationdate;
    char *modificationdate;
} Metadata;

// Function for extracting metadata from a file
Metadata extract_metadata(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Metadata metadata = {NULL, 0, NULL, NULL, NULL};

    file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the first line to get the file size
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Could not read file size from %s\n", filename);
        exit(1);
    }

    metadata.filesize = atoi(line);

    // Read the second line to get the file type
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Could not read file type from %s\n", filename);
        exit(1);
    }

    metadata.filetype = strdup(line);

    // Read the third line to get the creation date
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Could not read creation date from %s\n", filename);
        exit(1);
    }

    metadata.creationdate = strdup(line);

    // Read the fourth line to get the modification date
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        fprintf(stderr, "Error: Could not read modification date from %s\n", filename);
        exit(1);
    }

    metadata.modificationdate = strdup(line);

    // Close the file
    fclose(file);

    // Set the filename
    metadata.filename = strdup(filename);

    return metadata;
}

// Function for printing the metadata
void print_metadata(Metadata metadata) {
    printf("Filename: %s\n", metadata.filename);
    printf("File size: %d bytes\n", metadata.filesize);
    printf("File type: %s\n", metadata.filetype);
    printf("Creation date: %s\n", metadata.creationdate);
    printf("Modification date: %s\n", metadata.modificationdate);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    Metadata metadata;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Extract the metadata
    metadata = extract_metadata(filename);

    // Print the metadata
    print_metadata(metadata);

    // Free the memory used by the metadata
    free(metadata.filename);
    free(metadata.filetype);
    free(metadata.creationdate);
    free(metadata.modificationdate);

    return 0;
}