//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int read_metadata(FILE *file, metadata_t **metadata, int *metadata_count) {
    char line[MAX_LINE_LENGTH];
    char *name = NULL;
    char *value = NULL;
    int name_len = 0;
    int value_len = 0;
    int state = 0;

    *metadata = NULL;
    *metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_len = strlen(line);
        if (line_len == 0 || line[0] == '#') {
            continue;
        }

        if (state == 0) {
            name = strdup(line);
            name_len = strlen(name);
        } else if (state == 1) {
            value = strdup(line);
            value_len = strlen(value);

            metadata_t *new_metadata = (metadata_t *)malloc(sizeof(metadata_t));
            new_metadata->name = name;
            new_metadata->value = value;
            (*metadata) = realloc(*metadata, sizeof(metadata_t) * (*metadata_count + 1));
            (*metadata)[*metadata_count] = *new_metadata;
            (*metadata_count)++;

            state = 0;
        }
    }

    return 0;
}

int write_metadata(FILE *file, metadata_t *metadata, int metadata_count) {
    for (int i = 0; i < metadata_count; i++) {
        fprintf(file, "%s: %s\n", metadata[i].name, metadata[i].value);
    }

    return 0;
}

int main() {
    char filename[1024];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    metadata_t *metadata = NULL;
    int metadata_count = 0;

    read_metadata(file, &metadata, &metadata_count);

    fclose(file);

    printf("Metadata:\n");
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    free(metadata);

    return 0;
}