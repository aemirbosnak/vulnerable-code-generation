//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define a structure to store metadata information
typedef struct {
    char *filename;
    int filesize;
    char *author;
    char *title;
    char *date;
} Metadata;

// Function to extract metadata from a file
Metadata* extractMetadata(char *filename) {
    FILE *file;
    Metadata *metadata = NULL;
    char line[256];
    char *key = NULL, *value = NULL;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Initialize metadata structure
    metadata = (Metadata*) malloc(sizeof(Metadata));
    metadata->filename = strdup(filename);

    // Read the file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Check if the line contains a metadata key-value pair
        if (sscanf(line, "%*s %*s=\"%[^\"]\"", value) == 1) {
            // Extract the metadata key and value
            key = strtok(line, " ");
            value = strdup(value);

            // Update metadata structure
            if (strcmp(key, "author") == 0) {
                free(metadata->author);
                metadata->author = value;
            } else if (strcmp(key, "title") == 0) {
                free(metadata->title);
                metadata->title = value;
            } else if (strcmp(key, "date") == 0) {
                free(metadata->date);
                metadata->date = value;
            }
        }
    }

    // Close the file
    fclose(file);

    // Free memory
    free(key);
    free(value);

    return metadata;
}

// Function to print metadata information
void printMetadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);
}

// Main function
int main(int argc, char *argv[]) {
    Metadata *metadata = extractMetadata(argv[1]);
    if (metadata!= NULL) {
        printMetadata(metadata);
        free(metadata->author);
        free(metadata->title);
        free(metadata->date);
        free(metadata);
    }

    return 0;
}