//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000

// Struct to hold key-value pairs
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

// Function to extract metadata from a file
void extract_metadata(FILE *file, metadata_t *metadata) {
    char line[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    // Read the first line for the file name
    fgets(line, MAX_LINE_LENGTH, file);
    strcpy(metadata->key, "filename");
    strcpy(metadata->value, line);

    // Extract other metadata
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (sscanf(line, "%s: %s", key, value) == 2) {
            strcpy(metadata->key, key);
            strcpy(metadata->value, value);
        }
    }
}

// Function to print metadata
void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->value);
    printf("Metadata:\n");
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        if (metadata->key[i] == '\0') {
            break;
        }
        printf("%s: %s\n", metadata->key, metadata->value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    metadata_t metadata;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    extract_metadata(file, &metadata);
    print_metadata(&metadata);

    fclose(file);
    return 0;
}