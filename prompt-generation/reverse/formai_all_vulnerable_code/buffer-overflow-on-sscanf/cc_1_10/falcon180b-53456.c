//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a metadata record
typedef struct {
    char *key;
    char *value;
} metadata_record_t;

// Function to extract metadata from a file
void extract_metadata(FILE *file, metadata_record_t *metadata) {
    char line[1024];
    char *key, *value;

    // Read the first line of the file
    if (fgets(line, sizeof(line), file) == NULL) {
        return;
    }

    // Parse the metadata from the first line
    if (sscanf(line, "Metadata: %s=%s", key, value)!= 2) {
        return;
    }

    // Allocate memory for the metadata record
    metadata->key = strdup(key);
    metadata->value = strdup(value);
}

// Function to print metadata
void print_metadata(metadata_record_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file;
    metadata_record_t metadata;

    // Open the file
    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Extract metadata from the file
    extract_metadata(file, &metadata);

    // Print metadata
    print_metadata(&metadata);

    // Close the file
    fclose(file);

    return 0;
}