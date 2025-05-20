//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_VAL_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
} metadata_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_metadata = 0;
    metadata_t *metadata = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *key = strtok(line, ":");
        char *val = strtok(NULL, ":");
        if (key == NULL || val == NULL) {
            continue;
        }

        if (num_metadata == 0) {
            metadata = (metadata_t *)malloc(sizeof(metadata_t));
            num_metadata++;
        } else {
            metadata = (metadata_t *)realloc(metadata, sizeof(metadata_t) * num_metadata);
            num_metadata++;
        }

        strncpy(metadata[num_metadata - 1].key, key, MAX_KEY_LEN);
        strncpy(metadata[num_metadata - 1].val, val, MAX_VAL_LEN);
    }

    fclose(fp);

    printf("Number of metadata: %d\n", num_metadata);

    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s\nValue: %s\n", metadata[i].key, metadata[i].val);
    }

    free(metadata);
    return 0;
}