//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

typedef struct {
    int count;
    metadata_t *metadata;
} metadata_list_t;

int compare_metadata_key(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void add_metadata(metadata_list_t *list, char *key, char *value) {
    if (list->count >= MAX_LINE_LENGTH) {
        fprintf(stderr, "Error: Maximum number of metadata reached.\n");
        exit(1);
    }

    metadata_t *new_metadata = malloc(sizeof(metadata_t));
    new_metadata->key = strdup(key);
    new_metadata->value = strdup(value);

    list->metadata = realloc(list->metadata, sizeof(metadata_t) * (list->count + 1));
    list->metadata[list->count] = *new_metadata;
    list->count++;
}

void print_metadata_list(metadata_list_t *list) {
    qsort(list->metadata, list->count, sizeof(metadata_t), compare_metadata_key);

    for (int i = 0; i < list->count; i++) {
        metadata_t *metadata = &list->metadata[i];
        printf("%s: %s\n", metadata->key, metadata->value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    metadata_list_t metadata_list = {0};

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *key_value_pair = strchr(line, ':');
        if (key_value_pair == NULL) {
            continue;
        }

        *key_value_pair = '\0';
        char *key = line;
        char *value = key_value_pair + 1;

        add_metadata(&metadata_list, key, value);
    }

    print_metadata_list(&metadata_list);

    return 0;
}