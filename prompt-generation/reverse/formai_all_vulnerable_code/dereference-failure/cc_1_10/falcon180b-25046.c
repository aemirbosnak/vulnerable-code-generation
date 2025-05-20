//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *line) {
    char *name = NULL;
    char *value = NULL;
    char *delimiter = strchr(line, ':');

    if (delimiter == NULL) {
        return NULL;
    }

    *delimiter = '\0';
    name = line;
    value = delimiter + 1;

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->name = strdup(name);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    metadata_t *metadata = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata = parse_metadata(line);

        if (metadata!= NULL) {
            print_metadata(metadata);
            free_metadata(metadata);
        }
    }

    fclose(file);
    return 0;
}