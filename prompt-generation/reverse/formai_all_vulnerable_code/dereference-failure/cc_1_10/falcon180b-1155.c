//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_parse(char *metadata_str) {
    metadata_t *metadata = NULL;
    char *line = NULL;
    size_t line_len = 0;
    char *key = NULL;
    char *value = NULL;

    metadata = calloc(1, sizeof(metadata_t));

    line = strtok_r(metadata_str, "\n", &line_len);
    while (line!= NULL) {
        if (strlen(line) == 0) {
            line = strtok_r(NULL, "\n", &line_len);
            continue;
        }

        key = strtok_r(line, ":", &line_len);
        value = strtok_r(NULL, "\n", &line_len);

        metadata->key = strdup(key);
        metadata->value = strdup(value);

        line = strtok_r(NULL, "\n", &line_len);
    }

    return metadata;
}

void metadata_free(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata;

    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        metadata = metadata_parse(line);
        metadata_print(metadata);
        metadata_free(metadata);
    }

    fclose(fp);

    return 0;
}