//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYS 100
#define MAX_VALUES 100

typedef struct {
    char *key;
    char *value;
} Metadata;

typedef struct {
    Metadata *metadata;
    int num_metadata;
} MetadataExtractor;

int init_metadata_extractor(MetadataExtractor *extractor) {
    extractor->metadata = malloc(MAX_KEYS * sizeof(Metadata));
    if (extractor->metadata == NULL) {
        printf("Error: failed to allocate memory for metadata\n");
        return 1;
    }
    extractor->num_metadata = 0;
    return 0;
}

int add_metadata(MetadataExtractor *extractor, char *key, char *value) {
    if (extractor->num_metadata >= MAX_KEYS) {
        printf("Error: maximum number of metadata reached\n");
        return 1;
    }
    extractor->metadata[extractor->num_metadata].key = strdup(key);
    extractor->metadata[extractor->num_metadata].value = strdup(value);
    extractor->num_metadata++;
    return 0;
}

int extract_metadata(MetadataExtractor *extractor, char *line) {
    char *key, *value;
    char *token = strtok(line, ":");
    if (token == NULL) {
        printf("Error: invalid metadata format\n");
        return 1;
    }
    key = strdup(token);
    token = strtok(NULL, ":");
    if (token == NULL) {
        printf("Error: invalid metadata format\n");
        free(key);
        return 1;
    }
    value = strdup(token);
    add_metadata(extractor, key, value);
    free(key);
    free(value);
    return 0;
}

int print_metadata(MetadataExtractor *extractor) {
    int i;
    for (i = 0; i < extractor->num_metadata; i++) {
        printf("%s: %s\n", extractor->metadata[i].key, extractor->metadata[i].value);
    }
    return 0;
}

int main() {
    MetadataExtractor extractor;
    char line[MAX_LINE_LENGTH];
    char *filename = "metadata.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: failed to open metadata file\n");
        return 1;
    }
    if (init_metadata_extractor(&extractor)!= 0) {
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (extract_metadata(&extractor, line)!= 0) {
            return 1;
        }
    }
    fclose(file);
    if (print_metadata(&extractor)!= 0) {
        return 1;
    }
    return 0;
}