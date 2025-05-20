//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

void parse_metadata(char *line, metadata_t *metadata) {
    char *equal_pos = strchr(line, '=');
    if (equal_pos == NULL) {
        return;
    }
    *equal_pos = '\0';
    metadata->key = strdup(line);
    metadata->value = strdup(equal_pos + 1);
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;

    file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_metadata(line, &metadata);
        print_metadata(&metadata);
        free_metadata(&metadata);
    }

    fclose(file);
    return 0;
}