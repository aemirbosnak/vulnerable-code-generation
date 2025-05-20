//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *line) {
    char *key = NULL;
    char *value = NULL;
    char *delimiter = "=";
    char *token = strtok(line, delimiter);

    if (token == NULL) {
        return NULL;
    }

    key = strdup(token);

    token = strtok(NULL, delimiter);

    if (token == NULL) {
        free(key);
        return NULL;
    }

    value = strdup(token);

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = key;
    metadata->value = value;

    return metadata;
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main() {
    FILE *file = fopen("metadata.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        metadata_t *metadata = metadata_parse(line);

        if (metadata!= NULL) {
            metadata_print(metadata);
        }
    }

    fclose(file);

    return 0;
}