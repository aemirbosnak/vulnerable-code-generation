//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_SIZE 256
#define MAX_KEY_SIZE 100
#define MAX_VALUE_SIZE 150

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} MetadataEntry;

typedef struct {
    MetadataEntry entries[MAX_METADATA_SIZE];
    size_t count;
} MetadataExtractor;

// Function prototypes
void init_metadata_extractor(MetadataExtractor *extractor);
void add_metadata(MetadataExtractor *extractor, const char *key, const char *value);
const char *get_metadata_value(const MetadataExtractor *extractor, const char *key);
void print_all_metadata(const MetadataExtractor *extractor);
void parse_metadata_file(MetadataExtractor *extractor, const char *filename);

int main(int argc, char *argv[]) {
    MetadataExtractor extractor;
    init_metadata_extractor(&extractor);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_metadata_file(&extractor, argv[1]);
    
    printf("Extracted Metadata:\n");
    print_all_metadata(&extractor);

    return EXIT_SUCCESS;
}

void init_metadata_extractor(MetadataExtractor *extractor) {
    extractor->count = 0;
}

void add_metadata(MetadataExtractor *extractor, const char *key, const char *value) {
    if (extractor->count >= MAX_METADATA_SIZE) {
        fprintf(stderr, "Error: Maximum metadata size reached!\n");
        return;
    }
    strncpy(extractor->entries[extractor->count].key, key, MAX_KEY_SIZE - 1);
    strncpy(extractor->entries[extractor->count].value, value, MAX_VALUE_SIZE - 1);
    extractor->count++;
}

const char *get_metadata_value(const MetadataExtractor *extractor, const char *key) {
    for (size_t i = 0; i < extractor->count; i++) {
        if (strcmp(extractor->entries[i].key, key) == 0) {
            return extractor->entries[i].value;
        }
    }
    return NULL;
}

void print_all_metadata(const MetadataExtractor *extractor) {
    for (size_t i = 0; i < extractor->count; i++) {
        printf("%s: %s\n", extractor->entries[i].key, extractor->entries[i].value);
    }
}

void parse_metadata_file(MetadataExtractor *extractor, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    char line[MAX_METADATA_SIZE];
    while (fgets(line, sizeof(line), file)) {
        char key[MAX_KEY_SIZE];
        char value[MAX_VALUE_SIZE];
        if (sscanf(line, "%s : %[^\n]", key, value) == 2) {
            add_metadata(extractor, key, value);
        } else {
            fprintf(stderr, "Warning: Invalid line format: %s", line);
        }
    }

    fclose(file);
}