//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

typedef struct {
    metadata_t *metadata;
    int num_metadata;
} metadata_list_t;

metadata_t *create_metadata(char *name, char *value) {
    metadata_t *metadata = (metadata_t *) malloc(sizeof(metadata_t));
    metadata->name = strdup(name);
    metadata->value = strdup(value);
    return metadata;
}

void add_metadata(metadata_list_t *list, metadata_t *metadata) {
    list->metadata = (metadata_t *) realloc(list->metadata, sizeof(metadata_t) * (list->num_metadata + 1));
    list->metadata[list->num_metadata] = *metadata;
    list->num_metadata++;
}

void print_metadata_list(metadata_list_t *list) {
    int i;
    for (i = 0; i < list->num_metadata; i++) {
        printf("%s: %s\n", list->metadata[i].name, list->metadata[i].value);
    }
}

void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

void free_metadata_list(metadata_list_t *list) {
    int i;
    for (i = 0; i < list->num_metadata; i++) {
        free_metadata(list->metadata + i);
    }
    free(list->metadata);
    free(list);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *token;
    char *value;
    metadata_list_t metadata_list = { NULL, 0 };

    printf("Enter the name of the metadata file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }
        metadata_t *metadata = create_metadata(token, value);
        add_metadata(&metadata_list, metadata);
    }

    fclose(file);

    print_metadata_list(&metadata_list);

    free_metadata_list(&metadata_list);

    return 0;
}