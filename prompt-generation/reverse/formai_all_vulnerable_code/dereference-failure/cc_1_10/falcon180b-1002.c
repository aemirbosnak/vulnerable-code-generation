//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    char *delimiter = "=";
    char *name = strtok(line, delimiter);
    char *value = strtok(NULL, delimiter);

    Metadata *metadata = (Metadata *)malloc(sizeof(Metadata));
    metadata->name = strdup(name);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("%s: %s\n", metadata->name, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Metadata *metadata = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            if (metadata!= NULL) {
                print_metadata(metadata);
                free(metadata->name);
                free(metadata->value);
                free(metadata);
                metadata = NULL;
            }

            char *comment = strchr(line, '#');
            if (comment!= NULL) {
                *comment = '\0';
            }

            printf("%s\n", line);
        } else {
            if (metadata == NULL) {
                metadata = parse_metadata(line);
            } else {
                printf("Error: Invalid metadata format\n");
                free(metadata->name);
                free(metadata->value);
                free(metadata);
                metadata = NULL;
            }
        }
    }

    if (metadata!= NULL) {
        print_metadata(metadata);
        free(metadata->name);
        free(metadata->value);
        free(metadata);
    }

    fclose(file);

    return 0;
}