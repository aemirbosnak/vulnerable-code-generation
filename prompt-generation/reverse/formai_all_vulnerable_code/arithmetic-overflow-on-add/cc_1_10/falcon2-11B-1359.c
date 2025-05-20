//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    char* data;
} Metadata;

Metadata readMetadata(FILE* file) {
    Metadata metadata;
    metadata.size = 0;
    metadata.data = NULL;

    if (file == NULL) {
        fprintf(stderr, "Error: Invalid file\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    metadata.size = ftell(file);
    rewind(file);

    metadata.data = malloc(metadata.size + 1);
    if (metadata.data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    fread(metadata.data, sizeof(char), metadata.size, file);
    metadata.data[metadata.size] = '\0';

    return metadata;
}

void printMetadata(Metadata metadata) {
    printf("Size: %d\n", metadata.size);
    printf("Data: %s\n", metadata.data);
}

int main() {
    FILE* file = fopen("metadata.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    Metadata metadata = readMetadata(file);
    printMetadata(metadata);

    fclose(file);

    free(metadata.data);

    return 0;
}