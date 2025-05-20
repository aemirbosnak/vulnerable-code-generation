//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 100) // 100 MB

typedef struct {
    char *name;
    int value;
} metadata_t;

void extract_metadata(const char *filename, metadata_t *metadata) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    char header[4];
    fread(header, 1, 4, file);
    if (memcmp(header, "FORM", 4)!= 0) {
        fprintf(stderr, "File '%s' is not a valid metadata file\n", filename);
        exit(1);
    }

    metadata->name = malloc(MAX_FILE_SIZE);
    metadata->value = 0;

    char *ptr = metadata->name;
    while (fread(header, 1, 4, file) == 4) {
        if (memcmp(header, "name", 4) == 0) {
            fread(ptr, 1, fgetc(file), file);
            ptr += fgetc(file);
        } else if (memcmp(header, "value", 5) == 0) {
            metadata->value = fgetc(file);
        }
    }

    fclose(file);
}

int main() {
    metadata_t metadata;
    extract_metadata("metadata.bin", &metadata);

    printf("Name: %s\n", metadata.name);
    printf("Value: %d\n", metadata.value);

    free(metadata.name);
    return 0;
}