//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 2048

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *line) {
    char *name = NULL;
    char *value = NULL;
    char *pos = line;
    char *start = pos;

    // Find the start of the name
    while (*pos!= '=' && *pos!= ':' && *pos!= '\0') {
        pos++;
    }

    if (*pos == '\0') {
        printf("Invalid metadata: %s\n", line);
        return NULL;
    }

    *pos = '\0';
    name = strdup(start);
    pos++;

    // Find the start of the value
    while (*pos!= '\0' && isspace(*pos)) {
        pos++;
    }

    if (*pos == '\0') {
        printf("Invalid metadata: %s\n", line);
        free(name);
        return NULL;
    }

    *pos = '\0';
    value = strdup(pos);

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->name = name;
    metadata->value = value;

    return metadata;
}

void metadata_free(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

void metadata_print(metadata_t *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Value: %s\n", metadata->value);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *pos = line;
        while (isspace(*pos)) {
            pos++;
        }

        if (*pos == '#' || *pos == '\0') {
            continue;
        }

        metadata_t *metadata = metadata_parse(pos);
        if (metadata!= NULL) {
            metadata_print(metadata);
            metadata_free(metadata);
        }
    }

    fclose(file);

    return 0;
}