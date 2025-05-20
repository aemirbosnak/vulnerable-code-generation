//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from a file
void extract_metadata(const char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *metadata = NULL;
    size_t metadata_len = 0;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    // Read the first line (assumes metadata is on the first line)
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error: Could not read metadata from file %s\n", filename);
        exit(1);
    }

    // Extract the metadata
    metadata = strchr(line, ':');
    if (metadata == NULL) {
        printf("Error: Invalid metadata format in file %s\n", filename);
        exit(1);
    }
    metadata++; // Skip the colon
    metadata_len = strlen(metadata);

    // Print the metadata
    printf("Metadata for file %s:\n", filename);
    printf("  Length: %zu\n", metadata_len);
    printf("  Value:  %s\n", metadata);

    // Close the file
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    extract_metadata(argv[1]);

    return 0;
}