//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 256

typedef struct {
    char *name;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return 1;
    }

    metadata_t metadata[MAX_TOKENS];
    int num_metadata = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_metadata >= MAX_TOKENS) {
            fprintf(stderr, "Error: too many metadata tokens\n");
            fclose(file);
            return 1;
        }

        char *token = strtok(line, ": ");
        if (token == NULL) {
            continue;
        }

        metadata[num_metadata].name = strdup(token);
        token = strtok(NULL, ": ");
        if (token == NULL) {
            fprintf(stderr, "Error: missing metadata value\n");
            fclose(file);
            return 1;
        }

        metadata[num_metadata].value = strdup(token);
        num_metadata++;
    }

    if (num_metadata == 0) {
        fprintf(stderr, "Error: no metadata found\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Metadata:\n");
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }

    return 0;
}