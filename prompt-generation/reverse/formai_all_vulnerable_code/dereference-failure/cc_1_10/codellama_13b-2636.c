//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: active
/*
 * Unique C Metadata Extractor example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a file
void extractMetadata(const char *filename) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Read the first line of the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);
    if (read == -1) {
        printf("Error reading file %s\n", filename);
        return;
    }

    // Extract the metadata from the first line
    char *metadata = strtok(line, " ");
    if (metadata == NULL) {
        printf("Error extracting metadata from file %s\n", filename);
        return;
    }

    // Print the extracted metadata
    printf("Metadata: %s\n", metadata);

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Check if the filename was provided as an argument
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file
    extractMetadata(argv[1]);

    return 0;
}