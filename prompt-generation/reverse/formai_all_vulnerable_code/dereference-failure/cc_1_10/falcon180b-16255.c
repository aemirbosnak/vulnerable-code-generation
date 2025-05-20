//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 512

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *parse_metadata(char *metadata_str) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    char *token = strtok(metadata_str, "=");
    if (token == NULL || strcmp(token, "name")!= 0) {
        printf("Invalid metadata format.\n");
        exit(1);
    }
    metadata->name = strdup(token);
    token = strtok(NULL, "=");
    if (token == NULL) {
        printf("Invalid metadata format.\n");
        exit(1);
    }
    metadata->value = strdup(token);
    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    metadata_t *metadata;

    printf("Enter the name of the file containing metadata:\n");
    scanf("%s", file_name);

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        metadata = parse_metadata(line);
        print_metadata(metadata);
        free_metadata(metadata);
    }

    fclose(file);

    return 0;
}