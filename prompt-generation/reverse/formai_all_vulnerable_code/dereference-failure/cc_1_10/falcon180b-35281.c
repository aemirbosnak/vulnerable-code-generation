//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Maximum length of a line

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    int metadata_count = 0;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Check if the line contains metadata
        char *metadata_start = strstr(line, "<!--");
        char *metadata_end = strstr(line, "-->");

        if (metadata_start!= NULL && metadata_end!= NULL) {
            // Extract the metadata from the line
            char *metadata_value = metadata_start + strlen("<!--");
            char *metadata_key_start = metadata_value;
            char *metadata_key_end = strchr(metadata_value, ':');

            // Allocate memory for the metadata struct
            metadata_t *new_metadata = malloc(sizeof(metadata_t));

            // Copy the key and value into the metadata struct
            new_metadata->key = strndup(metadata_key_start, metadata_key_end - metadata_key_start);
            new_metadata->value = strndup(metadata_key_end + 1, metadata_end - metadata_key_end - 1);

            // Add the metadata to the list
            metadata = realloc(metadata, sizeof(metadata_t) * ++metadata_count);
            metadata[metadata_count - 1] = *new_metadata;
        }
    }

    // Print the extracted metadata
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    // Free the allocated memory
    for (int i = 0; i < metadata_count; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }
    free(metadata);

    fclose(file);

    return 0;
}