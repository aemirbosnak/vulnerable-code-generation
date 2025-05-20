//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: shocked
// Unique C Metadata Extractor Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store metadata information
typedef struct {
    char* key;
    char* value;
} Metadata;

// Define a function to extract metadata from a file
void extractMetadata(char* filePath, Metadata* metadata) {
    // Open the file in read mode
    FILE* file = fopen(filePath, "r");

    // Read the first line of the file
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, file);

    // Check if the file is empty
    if (read == -1) {
        printf("Error: File is empty.\n");
        return;
    }

    // Extract the metadata from the first line
    char* key = strtok(line, ":");
    char* value = strtok(NULL, ":");

    // Store the metadata in the structure
    metadata->key = key;
    metadata->value = value;

    // Close the file
    fclose(file);
}

// Define a function to print the metadata
void printMetadata(Metadata* metadata) {
    printf("Metadata: {");
    printf("key: %s, ", metadata->key);
    printf("value: %s", metadata->value);
    printf("}\n");
}

// Define the main function
int main(int argc, char** argv) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Get the file path from the argument
    char* filePath = argv[1];

    // Create a new Metadata structure
    Metadata* metadata = (Metadata*)malloc(sizeof(Metadata));

    // Extract the metadata from the file
    extractMetadata(filePath, metadata);

    // Print the metadata
    printMetadata(metadata);

    // Free the memory allocated for the structure
    free(metadata);

    return 0;
}