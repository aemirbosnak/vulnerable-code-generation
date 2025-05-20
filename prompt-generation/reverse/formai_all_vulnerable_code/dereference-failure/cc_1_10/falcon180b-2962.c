//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *metadata_create(char *key, char *value) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->key = strdup(key);
    metadata->value = strdup(value);
    return metadata;
}

void metadata_destroy(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

void metadata_print(Metadata *metadata) {
    printf("%s: %s\n", metadata->key, metadata->value);
}

int metadata_compare(Metadata *a, Metadata *b) {
    return strcmp(a->key, b->key);
}

void metadata_sort(Metadata **metadata, int count) {
    qsort(metadata, count, sizeof(Metadata *), metadata_compare);
}

char *metadata_get_value(Metadata *metadata, char *key) {
    if (strcmp(metadata->key, key) == 0) {
        return metadata->value;
    }
    return NULL;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    Metadata **metadata = NULL;
    int count = 0;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        count++;
        metadata = realloc(metadata, sizeof(Metadata *) * count);
        key = strtok(line, ":");
        value = strtok(NULL, "\n");
        metadata[count-1] = metadata_create(key, value);
    }

    fclose(fp);

    metadata_sort(metadata, count);

    for (int i = 0; i < count; i++) {
        metadata_print(metadata[i]);
    }

    for (int i = 0; i < count; i++) {
        metadata_destroy(metadata[i]);
        free(metadata[i]);
    }
    free(metadata);

    return 0;
}