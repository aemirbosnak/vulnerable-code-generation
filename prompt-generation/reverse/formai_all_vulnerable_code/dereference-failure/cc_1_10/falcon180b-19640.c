//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int compare_metadata(const void *a, const void *b) {
    metadata_t *ma = (metadata_t *)a;
    metadata_t *mb = (metadata_t *)b;

    return strcmp(ma->key, mb->key);
}

metadata_t *parse_metadata_line(char *line) {
    char *token = strtok(line, ":");
    if (token == NULL) {
        return NULL;
    }

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = strdup(token);

    token = strtok(NULL, ":");
    if (token == NULL) {
        metadata->value = strdup("");
    } else {
        metadata->value = strdup(token);
    }

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("%s: %s\n", metadata->key, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata-file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    metadata_t **metadata_list = NULL;
    size_t metadata_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata_t *metadata = parse_metadata_line(line);
        if (metadata!= NULL) {
            metadata_list = realloc(metadata_list, sizeof(metadata_t *) * (metadata_count + 1));
            metadata_list[metadata_count++] = metadata;
        }
    }

    fclose(file);

    qsort(metadata_list, metadata_count, sizeof(metadata_t *), compare_metadata);

    for (size_t i = 0; i < metadata_count; i++) {
        print_metadata(metadata_list[i]);
    }

    for (size_t i = 0; i < metadata_count; i++) {
        free(metadata_list[i]->key);
        free(metadata_list[i]->value);
        free(metadata_list[i]);
    }
    free(metadata_list);

    return 0;
}