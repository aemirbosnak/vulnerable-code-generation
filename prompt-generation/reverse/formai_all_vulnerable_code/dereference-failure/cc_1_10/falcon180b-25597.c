//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *key, *value;
    metadata_t *metadata;
    int num_metadata = 0;
    int line_num = 0;

    metadata = malloc(sizeof(metadata_t) * 100);

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line_num++;
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            printf("Invalid metadata on line %d.\n", line_num);
            continue;
        }

        metadata[num_metadata].key = strdup(key);
        metadata[num_metadata].value = strdup(value);
        num_metadata++;
    }

    fclose(fp);

    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].key);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}