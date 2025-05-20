//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototype for metadata extraction
int extract_metadata(FILE *file, char **metadata);

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];
    char **metadata;

    // Open the input file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    // Allocate memory for metadata array
    metadata = malloc(sizeof(char *));
    if (metadata == NULL) {
        printf("Error: Unable to allocate memory for metadata\n");
        fclose(file);
        return 1;
    }

    // Extract metadata from file
    int metadata_count = extract_metadata(file, metadata);
    if (metadata_count == 0) {
        printf("No metadata found in file %s\n", filename);
        free(metadata);
        fclose(file);
        return 0;
    }

    // Print extracted metadata
    printf("Metadata found in file %s:\n", filename);
    for (int i = 0; i < metadata_count; i++) {
        printf("%s\n", metadata[i]);
        free(metadata[i]);
    }
    free(metadata);
    fclose(file);
    return 0;
}

// Function to extract metadata from file
int extract_metadata(FILE *file, char **metadata) {
    char line[1024];
    char *key, *value;
    int metadata_count = 0;

    // Loop through each line in the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Check if the line contains metadata
        if (line[0] == '#' && strchr(line, ':')!= NULL) {
            // Extract key-value pair from line
            key = strtok(line, ":");
            value = strtok(NULL, "\n");

            // Allocate memory for new metadata string
            metadata[metadata_count] = malloc(sizeof(char) * (strlen(key) + strlen(value) + 2));
            if (metadata[metadata_count] == NULL) {
                printf("Error: Unable to allocate memory for metadata\n");
                return 0;
            }

            // Combine key and value with a space separator
            sprintf(metadata[metadata_count], "%s %s", key, value);
            metadata_count++;
        }
    }

    // Return the number of metadata items extracted
    return metadata_count;
}