//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    size_t metadata_count = 0;
    size_t metadata_capacity = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *key, *value;
        size_t key_length, value_length;

        // find the first non-space character
        key = line;
        while (isspace(*key)) {
            key++;
        }

        // find the end of the key
        key_length = strlen(key);
        while (key_length > 0 && isspace(key[key_length - 1])) {
            key[--key_length] = '\0';
        }

        // find the start of the value
        while (isspace(*(key + key_length))) {
            key_length++;
        }

        // find the end of the value
        value = key + key_length;
        value_length = strlen(value);
        while (value_length > 0 && isspace(value[value_length - 1])) {
            value[--value_length] = '\0';
        }

        // add the metadata to the list
        if (metadata_count >= metadata_capacity) {
            metadata_capacity += 10;
            metadata = realloc(metadata, metadata_capacity * sizeof(metadata_t));
        }

        metadata[metadata_count].name = strdup(key);
        metadata[metadata_count].value = strdup(value);
        metadata_count++;
    }

    fclose(file);

    // print the metadata
    for (size_t i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    // free the metadata
    for (size_t i = 0; i < metadata_count; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}