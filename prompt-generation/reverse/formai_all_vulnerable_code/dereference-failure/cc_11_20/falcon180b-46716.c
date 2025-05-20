//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_KEYS 100

typedef struct {
    char *key;
    char *value;
} Metadata;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char delim = '=';
    int num_keys = 0;
    Metadata *metadata = NULL;

    if (argc == 1) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key = NULL;
        char *value = NULL;

        if (num_keys >= MAX_NUM_KEYS) {
            printf("Maximum number of keys reached\n");
            break;
        }

        if (line[0] == '#') {
            continue;
        }

        if ((key = strtok(line, &delim)) == NULL || (value = strtok(NULL, &delim)) == NULL) {
            continue;
        }

        if (metadata == NULL) {
            metadata = (Metadata *)malloc(sizeof(Metadata));
            metadata->key = strdup(key);
            metadata->value = strdup(value);
            num_keys++;
        } else {
            metadata = (Metadata *)realloc(metadata, sizeof(Metadata) * (num_keys + 1));
            metadata[num_keys - 1].key = strdup(key);
            metadata[num_keys - 1].value = strdup(value);
            num_keys++;
        }
    }

    fclose(fp);

    if (metadata == NULL) {
        printf("No metadata found in file %s\n", argv[1]);
        exit(1);
    }

    printf("Metadata:\n");

    for (int i = 0; i < num_keys; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    for (int i = 0; i < num_keys; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }

    free(metadata);

    return 0;
}