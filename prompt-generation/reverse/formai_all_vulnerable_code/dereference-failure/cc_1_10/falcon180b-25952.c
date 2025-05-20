//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYS 100

typedef struct {
    char *key;
    char *value;
} KeyValue;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    int num_keys = 0;
    KeyValue *metadata = NULL;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        key = strtok(line, ":");
        if (key == NULL) {
            continue;
        }

        value = strtok(NULL, ":");
        if (value == NULL) {
            continue;
        }

        if (num_keys >= MAX_KEYS) {
            printf("Too many metadata keys\n");
            fclose(fp);
            return 1;
        }

        metadata = realloc(metadata, sizeof(KeyValue) * ++num_keys);
        metadata[num_keys - 1].key = strdup(key);
        metadata[num_keys - 1].value = strdup(value);
    }

    fclose(fp);

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