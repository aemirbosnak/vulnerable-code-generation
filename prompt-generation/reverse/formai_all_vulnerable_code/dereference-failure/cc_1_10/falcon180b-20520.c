//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

metadata_t *metadata_create() {
    metadata_t *metadata = (metadata_t *) malloc(sizeof(metadata_t));
    if (!metadata) {
        printf("Error: failed to allocate memory for metadata.\n");
        exit(1);
    }
    memset(metadata, 0, sizeof(metadata_t));
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    free(metadata);
}

void metadata_add(metadata_t *metadata, const char *key, const char *value) {
    if (metadata->key[0]) {
        printf("Error: metadata already has a key.\n");
        return;
    }
    strncpy(metadata->key, key, MAX_KEY_LENGTH - 1);
    strncpy(metadata->value, value, MAX_VALUE_LENGTH - 1);
}

int metadata_parse(metadata_t *metadata, const char *line) {
    char *key = NULL;
    char *value = NULL;
    char *token = strtok(line, ":");
    if (!token) {
        printf("Error: invalid metadata format.\n");
        return -1;
    }
    key = strdup(token);
    token = strtok(NULL, ":");
    if (!token) {
        printf("Error: invalid metadata format.\n");
        free(key);
        return -1;
    }
    value = strdup(token);
    metadata_add(metadata, key, value);
    free(key);
    free(value);
    return 0;
}

void metadata_print(const metadata_t *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = metadata_create();

    file = fopen("example.txt", "r");
    if (!file) {
        printf("Error: failed to open file.\n");
        metadata_destroy(metadata);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (metadata_parse(metadata, line)) {
            metadata_destroy(metadata);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    metadata_print(metadata);
    metadata_destroy(metadata);

    return 0;
}