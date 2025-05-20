//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

metadata_t *metadata_create(void) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    if (!metadata) {
        fprintf(stderr, "Error: Failed to allocate memory for metadata.\n");
        exit(EXIT_FAILURE);
    }
    memset(metadata, 0, sizeof(metadata_t));
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    if (metadata) {
        free(metadata);
    }
}

int metadata_add(metadata_t *metadata, const char *key, const char *value) {
    if (!metadata ||!key ||!value) {
        fprintf(stderr, "Error: Invalid parameters.\n");
        return -1;
    }
    strncpy(metadata->key, key, MAX_KEY_SIZE);
    strncpy(metadata->value, value, MAX_VALUE_SIZE);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", argv[1]);
        return 1;
    }
    metadata_t *metadata = metadata_create();
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {
        char *key = strtok(line, ":");
        if (!key) {
            continue;
        }
        char *value = strtok(NULL, ":");
        if (!value) {
            continue;
        }
        metadata_add(metadata, key, value);
    }
    fclose(file);
    metadata_destroy(metadata);
    return 0;
}