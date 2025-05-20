//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} metadata_t;

int compare_metadata(const void *a, const void *b) {
    metadata_t *metadata_a = (metadata_t *) a;
    metadata_t *metadata_b = (metadata_t *) b;

    return strcmp(metadata_a->key, metadata_b->key);
}

void extract_metadata(char *file_path) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    int metadata_count = 0;

    file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *key = strtok(line, ": ");
        char *value = strtok(NULL, ": ");

        if (key!= NULL && value!= NULL) {
            metadata = realloc(metadata, sizeof(metadata_t) * ++metadata_count);

            metadata[metadata_count - 1].key = strdup(key);
            metadata[metadata_count - 1].value = strdup(value);
        }
    }

    fclose(file);

    qsort(metadata, metadata_count, sizeof(metadata_t), compare_metadata);

    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    for (int i = 0; i < metadata_count; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }

    free(metadata);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];

    if (strlen(file_path) > MAX_FILE_NAME_LENGTH) {
        printf("Error: File path too long\n");
        return 1;
    }

    extract_metadata(file_path);

    return 0;
}