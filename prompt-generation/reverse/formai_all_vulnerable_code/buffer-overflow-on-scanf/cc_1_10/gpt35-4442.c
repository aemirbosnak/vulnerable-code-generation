//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_METADATA_SIZE 100

int main() {
    char file_name[MAX_FILE_NAME];
    char metadata[MAX_METADATA_SIZE];
    int i, j;

    // Prompt user for file name
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open file for reading in binary mode
    FILE* file_ptr = fopen(file_name, "rb");

    // Check if file exists
    if (file_ptr == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    // Read metadata from file
    for (i = 0; i < MAX_METADATA_SIZE; i++) {
        char current_char = fgetc(file_ptr);

        // Check if end of metadata
        if (current_char == '\n' || current_char == EOF) {
            metadata[i] = '\0';
            break;
        }

        metadata[i] = current_char;
    }

    // Display metadata
    printf("\nMETADATA:\n");
    printf("%s\n\n", metadata);

    // Extract data from metadata
    char key[MAX_METADATA_SIZE], value[MAX_METADATA_SIZE];
    int key_index = 0, value_index = 0;

    for (j = 0; j < i; j++) {
        char current_char = metadata[j];

        // Check for separator
        if (current_char == '=') {
            value[value_index] = '\0';  // Terminate value string
            key[key_index] = '\0';  // Terminate key string
            break;
        }

        // Check for whitespace
        if (current_char == ' ') {
            continue;
        }

        // Check for key/value separation
        if (current_char == ':') {
            continue;
        }

        // Add character to key or value string
        if (value_index == 0) {
            key[key_index++] = current_char;
        } else {
            value[value_index++] = current_char;
        }
    }

    // Display key and value
    printf("KEY: %s\n", key);
    printf("VALUE: %s\n", value);

    // Close file
    fclose(file_ptr);

    return 0;
}