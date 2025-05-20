//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdarg.h>

#define METADATA_EXTRACTOR_MAX_LENGTH 1024

typedef struct {
    const char *name;
    const char *value;
} Metadata;

void *metadata_extractor_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

Metadata *metadata_extractor_new(const char *name, const char *value) {
    Metadata *metadata = metadata_extractor_malloc(sizeof(Metadata));
    metadata->name = name;
    metadata->value = value;
    return metadata;
}

Metadata *metadata_extractor_new_from_string(const char *string) {
    char *name = metadata_extractor_malloc(METADATA_EXTRACTOR_MAX_LENGTH);
    char *value = metadata_extractor_malloc(METADATA_EXTRACTOR_MAX_LENGTH);
    int name_length = sscanf(string, "%s = %s", name, value);
    if (name_length != 2) {
        fprintf(stderr, "Error: Invalid metadata string '%s'.\n", string);
        exit(EXIT_FAILURE);
    }
    Metadata *metadata = metadata_extractor_new(name, value);
    free(name);
    free(value);
    return metadata;
}

Metadata **metadata_extractor_load(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'.\n", filename);
        exit(EXIT_FAILURE);
    }
    Metadata **metadata = metadata_extractor_malloc(sizeof(Metadata *) * METADATA_EXTRACTOR_MAX_LENGTH);
    char buffer[METADATA_EXTRACTOR_MAX_LENGTH];
    int i = 0;
    while (fgets(buffer, METADATA_EXTRACTOR_MAX_LENGTH, file) != NULL) {
        metadata[i] = metadata_extractor_new_from_string(buffer);
        i++;
    }
    fclose(file);
    return metadata;
}

void metadata_extractor_free(Metadata *metadata) {
    free((void *)metadata->name);
    free((void *)metadata->value);
    free(metadata);
}

void metadata_extractor_free_all(Metadata **metadata) {
    int i = 0;
    while (metadata[i] != NULL) {
        metadata_extractor_free(metadata[i]);
        i++;
    }
    free(metadata);
}

void metadata_extractor_print(const Metadata *metadata) {
    printf("%s = %s\n", metadata->name, metadata->value);
}

void metadata_extractor_print_all(const Metadata **metadata) {
    int i = 0;
    while (metadata[i] != NULL) {
        metadata_extractor_print(metadata[i]);
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: Usage: %s <metadata file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    const Metadata **metadata = metadata_extractor_load(argv[1]);
    metadata_extractor_print_all(metadata);
    metadata_extractor_free_all((Metadata **)metadata);
    return EXIT_SUCCESS;
}