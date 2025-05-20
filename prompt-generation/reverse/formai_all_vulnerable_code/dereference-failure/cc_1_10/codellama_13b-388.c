//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char* name;
    char* value;
} MetaData;

void extract_metadata(char* file_path, MetaData** metadata) {
    // Open the file for reading
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    // Read the file into a buffer
    char buffer[MAX_FILE_SIZE];
    fread(buffer, sizeof(char), MAX_FILE_SIZE, fp);

    // Close the file
    fclose(fp);

    // Extract metadata
    char* name;
    char* value;
    while ((name = strtok(buffer, " ")) != NULL) {
        value = strtok(NULL, " ");
        if (value != NULL) {
            MetaData* md = malloc(sizeof(MetaData));
            md->name = strdup(name);
            md->value = strdup(value);
            *metadata = md;
            metadata++;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    MetaData* metadata = NULL;
    extract_metadata(argv[1], &metadata);

    while (metadata != NULL) {
        printf("Name: %s, Value: %s\n", metadata->name, metadata->value);
        metadata++;
    }

    return 0;
}