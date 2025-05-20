//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256

typedef struct {
    char *key;
    char *value;
} Metadata;

void print_metadata(Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int compare_metadata(const void *a, const void *b) {
    Metadata *metadata_a = (Metadata *)a;
    Metadata *metadata_b = (Metadata *)b;

    return strcmp(metadata_a->key, metadata_b->key);
}

void free_metadata(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 2;
    }

    Metadata *metadata = NULL;
    size_t metadata_count = 0;
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            printf("Error: invalid metadata format on line '%s'\n", line);
            continue;
        }

        Metadata *new_metadata = malloc(sizeof(Metadata));
        new_metadata->key = strdup(key);
        new_metadata->value = strdup(value);
        metadata = realloc(metadata, sizeof(Metadata) * ++metadata_count);
        metadata[metadata_count - 1] = *new_metadata;
        free(new_metadata);
    }

    fclose(file);

    qsort(metadata, metadata_count, sizeof(Metadata), compare_metadata);

    for (size_t i = 0; i < metadata_count; i++) {
        print_metadata(&metadata[i]);
    }

    free(metadata);
    return 0;
}