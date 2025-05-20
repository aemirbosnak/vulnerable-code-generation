//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *line) {
    char *key_start = strstr(line, "key=");
    char *key_end = strstr(line, "value=");
    char *key = malloc(key_end - key_start + 1);
    char *value_start = strstr(line, "value=");
    char *value_end = strstr(line, "\n");
    char *value = malloc(value_end - value_start + 1);

    strncpy(key, key_start + 5, key_end - key_start - 5);
    strncpy(value, value_start + 7, value_end - value_start - 7);

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = key;
    metadata->value = value;

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

int main() {
    FILE *file = fopen("metadata.txt", "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata_t *metadata = parse_metadata(line);
        print_metadata(metadata);
        free(metadata->key);
        free(metadata->value);
        free(metadata);
    }

    fclose(file);

    return 0;
}