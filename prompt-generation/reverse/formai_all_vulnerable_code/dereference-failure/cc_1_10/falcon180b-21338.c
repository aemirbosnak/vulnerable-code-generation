//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a metadata key or value
#define MAX_METADATA_LENGTH 256

// Define the structure for a metadata key-value pair
typedef struct {
    char key[MAX_METADATA_LENGTH];
    char value[MAX_METADATA_LENGTH];
} Metadata;

// Function to extract metadata from a file
void extractMetadata(FILE *file, Metadata *metadata) {
    char line[MAX_METADATA_LENGTH];
    char *key, *value;

    // Read the first line of the file, which should contain the metadata
    fgets(line, MAX_METADATA_LENGTH, file);

    // Parse the metadata line
    key = strtok(line, ":");
    value = strtok(NULL, ":");

    // Copy the metadata key and value to the metadata structure
    strncpy(metadata->key, key, MAX_METADATA_LENGTH);
    strncpy(metadata->value, value, MAX_METADATA_LENGTH);
}

// Function to print the metadata
void printMetadata(Metadata *metadata) {
    printf("Metadata:\n");
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

// Main function
int main(int argc, char *argv[]) {
    FILE *file;
    Metadata metadata;

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Extract the metadata from the input file
    extractMetadata(file, &metadata);

    // Close the input file
    fclose(file);

    // Open the output file for writing
    file = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Print the metadata to the output file
    printMetadata(&metadata);

    // Close the output file
    fclose(file);

    return 0;
}