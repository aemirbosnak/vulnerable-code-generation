//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
// C Metadata Extractor Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store metadata information
typedef struct {
    char* name;
    char* value;
} Metadata;

// Function to extract metadata from a file
Metadata* extractMetadata(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    // Read the first line of the file
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fp);
    if (read == -1) {
        fclose(fp);
        return NULL;
    }

    // Extract the metadata from the first line
    char* name = strtok(line, ":");
    char* value = strtok(NULL, ":");

    // Create a new Metadata struct and populate it with the extracted data
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->name = name;
    metadata->value = value;

    // Close the file and return the Metadata struct
    fclose(fp);
    return metadata;
}

// Function to print the metadata information
void printMetadata(Metadata* metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

// Example usage of the metadata extractor
int main(int argc, char* argv[]) {
    // Extract the metadata from the file
    Metadata* metadata = extractMetadata("example.txt");

    // Print the metadata information
    printMetadata(metadata);

    // Free the metadata struct
    free(metadata);

    return 0;
}