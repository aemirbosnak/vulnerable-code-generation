//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    metadata_t *metadata = NULL;
    int num_metadata = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        metadata = realloc(metadata, sizeof(metadata_t) * ++num_metadata);
        metadata[num_metadata - 1].name = strdup(token);
        metadata[num_metadata - 1].value = strdup("");
        token = strtok(NULL, ":");
        while (token!= NULL) {
            strcat(metadata[num_metadata - 1].value, token);
            strcat(metadata[num_metadata - 1].value, " ");
            token = strtok(NULL, ":");
        }
        strcat(metadata[num_metadata - 1].value, "\n");
    }

    fclose(fp);

    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}