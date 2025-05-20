//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 256
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *line) {
    char *key = strtok(line, ":");
    char *value = strtok(NULL, ":");

    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->key = strdup(key);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    metadata_t *metadata = NULL;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[0] == '#' &&!metadata) {
            metadata = parse_metadata(line);
        } else {
            printf("Invalid metadata format.\n");
            free(line);
            fclose(fp);
            return 1;
        }
    }

    if (metadata == NULL) {
        printf("No metadata found.\n");
        free(line);
        fclose(fp);
        return 1;
    }

    print_metadata(metadata);

    free(line);
    fclose(fp);

    return 0;
}