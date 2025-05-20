//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 1024

// Data structure to store key-value pairs
typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} KeyValue;

// Function to extract metadata from a file
void extractMetadata(FILE *file, KeyValue *metadata) {
    char line[MAX_LINE_SIZE];
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];

    // Initialize metadata
    memset(metadata, 0, sizeof(KeyValue));

    // Extract metadata from file
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (sscanf(line, "%s: %s", key, value) == 2) {
            strncpy(metadata->key, key, MAX_KEY_SIZE);
            strncpy(metadata->value, value, MAX_VALUE_SIZE);
        }
    }
}

int main() {
    FILE *file;
    KeyValue metadata;

    // Open file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Extract metadata from file
    extractMetadata(file, &metadata);

    // Print metadata
    printf("Metadata:\n");
    printf("  Key: %s\n", metadata.key);
    printf("  Value: %s\n", metadata.value);

    // Close file
    fclose(file);

    return 0;
}