//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_METADATA 100

struct metadata {
    char *name;
    char *value;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_metadata = 0;
    struct metadata *metadata = malloc(sizeof(struct metadata) * MAX_NUM_METADATA);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            if (num_metadata >= MAX_NUM_METADATA) {
                printf("Error: too many metadata\n");
                free(metadata);
                fclose(file);
                return 1;
            }

            metadata[num_metadata].name = strdup(token);
            token = strtok(NULL, ":");
            if (token == NULL) {
                printf("Error: missing metadata value\n");
                free(metadata);
                fclose(file);
                return 1;
            }

            metadata[num_metadata].value = strdup(token);
            num_metadata++;

            token = strtok(NULL, ":");
        }
    }

    fclose(file);

    printf("Filename: %s\n", argv[1]);
    for (int i = 0; i < num_metadata; i++) {
        printf("Metadata %d:\n", i + 1);
        printf("Name: %s\n", metadata[i].name);
        printf("Value: %s\n", metadata[i].value);
    }

    for (int i = 0; i < num_metadata; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}