//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024

// Define the structure for a key-value pair
typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValuePair;

// Function to extract metadata from a line of text
void extractMetadata(char* line, KeyValuePair* metadata) {
    char* key = strtok(line, ":");
    char* value = strtok(NULL, ":");

    // Check if the line contains valid metadata
    if (key == NULL || value == NULL) {
        return;
    }

    // Copy the key and value into the metadata structure
    strncpy(metadata->key, key, MAX_KEY_SIZE);
    strncpy(metadata->value, value, MAX_VALUE_SIZE);
}

// Function to print the metadata for a given key
void printMetadata(KeyValuePair* metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n\n", metadata->value);
}

// Function to read metadata from a file
void readMetadataFromFile(FILE* file, char* key, KeyValuePair* metadata) {
    // Read the file line by line
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Check if the line contains the specified key
        if (strstr(line, key)!= NULL) {
            extractMetadata(line, metadata);
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", argv[1]);
        return 1;
    }

    // Read the metadata for the specified key
    KeyValuePair metadata;
    char* key = argv[2];
    readMetadataFromFile(file, key, &metadata);

    // Print the metadata
    printf("Metadata for key '%s':\n", key);
    printMetadata(&metadata);

    // Close the file
    fclose(file);

    return 0;
}