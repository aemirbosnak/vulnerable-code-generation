//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int main(int argc, char **argv) {
    metadata_t metadata;
    char line[MAX_LINE_SIZE];
    char *token;
    char *saveptr;
    FILE *input_file;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");

    if (input_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    metadata.name = malloc(MAX_LINE_SIZE);
    metadata.value = malloc(MAX_LINE_SIZE);

    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        token = strtok_r(line, ":", &saveptr);
        if (token!= NULL) {
            strcpy(metadata.name, token);

            token = strtok_r(NULL, ":", &saveptr);
            if (token!= NULL) {
                strcpy(metadata.value, token);

                printf("Name: %s\nValue: %s\n", metadata.name, metadata.value);
            }
        }
    }

    fclose(input_file);
    free(metadata.name);
    free(metadata.value);

    return 0;
}