//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

void extract_metadata(FILE *file, metadata_t *metadata) {
    char line[MAX_LINE_LENGTH];
    char *key;
    char *value;
    int in_metadata = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (in_metadata && line[0] == ':') {
            key = line + 1;
            value = strchr(key, ':');
            if (value!= NULL) {
                *value = '\0';
                value++;
            }
            metadata->name = strdup(key);
            metadata->value = strdup(value);
            in_metadata = 0;
        } else if (line[0] == '@') {
            in_metadata = 1;
        }
    }
}

void print_metadata(metadata_t *metadata) {
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image_file> <metadata_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    metadata_t metadata;
    extract_metadata(file, &metadata);

    if (metadata.name == NULL || metadata.value == NULL) {
        printf("Metadata not found.\n");
        fclose(file);
        return 1;
    }

    if (strcmp(metadata.name, argv[2])!= 0) {
        printf("Metadata name does not match.\n");
        fclose(file);
        return 1;
    }

    print_metadata(&metadata);

    fclose(file);
    return 0;
}