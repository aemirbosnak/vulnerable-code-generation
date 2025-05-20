//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int parse_metadata_line(char *line, metadata_t *metadata) {
    char *key_start = line;
    char *value_start = line;
    int key_length = 0;
    int value_length = 0;

    while (isspace(*value_start)) {
        value_start++;
        value_length++;
    }

    while (!isspace(*value_start)) {
        value_start++;
        value_length++;
    }

    while (isspace(*value_start)) {
        value_start++;
        value_length++;
    }

    metadata->key = malloc(key_length + 1);
    strncpy(metadata->key, key_start, key_length);
    metadata->key[key_length] = '\0';

    metadata->value = malloc(value_length + 1);
    strncpy(metadata->value, value_start, value_length);
    metadata->value[value_length] = '\0';

    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (parse_metadata_line(line, &metadata)) {
            printf("Key: %s\nValue: %s\n\n", metadata.key, metadata.value);
        }
    }

    free(metadata.key);
    free(metadata.value);
    fclose(file);

    return 0;
}