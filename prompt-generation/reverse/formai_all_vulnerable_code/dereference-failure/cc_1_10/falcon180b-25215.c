//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *parse_metadata(char *line) {
    Metadata *metadata = malloc(sizeof(Metadata));
    char *token = strtok(line, ": ");
    char *value = strtok(NULL, ": ");

    if (token == NULL || value == NULL) {
        free(metadata);
        return NULL;
    }

    metadata->name = strdup(token);
    metadata->value = strdup(value);

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Metadata *metadata = NULL;
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (line[0] == '#') {
            if (metadata!= NULL) {
                print_metadata(metadata);
                free(metadata->name);
                free(metadata->value);
                free(metadata);
                metadata = NULL;
            }

            char *comment = strchr(line, '#');
            if (comment!= NULL)
                *comment = '\0';

            printf("Comment: %s\n", line);
        } else {
            metadata = parse_metadata(line);
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