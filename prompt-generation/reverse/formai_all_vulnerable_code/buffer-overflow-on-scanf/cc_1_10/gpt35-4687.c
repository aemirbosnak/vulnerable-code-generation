//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

/* This function extracts metadata from the input file and returns it as a string */
char* extract_metadata(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        // File could not be opened
        return NULL;
    }

    char* metadata = (char*) malloc(MAX_SIZE * sizeof(char));
    if (!metadata) {
        // Memory allocation failed
        fclose(file);
        return NULL;
    }

    // Read the first line of the file
    char line[MAX_SIZE];
    fgets(line, MAX_SIZE, file);

    // Copy metadata from the first line
    if (strstr(line, "#METADATA:")) {
        strcpy(metadata, line + strlen("#METADATA:"));
        metadata[strlen(metadata) - 1] = '\0'; // Remove newline character
    } else {
        // No metadata found
        fclose(file);
        free(metadata);
        return NULL;
    }

    fclose(file);
    return metadata;
}

int main() {
    char filename[MAX_SIZE];
    printf("Enter the file name: ");
    scanf("%s", filename);

    char* metadata = extract_metadata(filename);
    if (metadata) {
        printf("Metadata: %s\n", metadata);
        free(metadata);
    } else {
        printf("No metadata found\n");
    }

    return 0;
}