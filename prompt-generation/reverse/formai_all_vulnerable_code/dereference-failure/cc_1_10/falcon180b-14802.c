//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_LINE_LEN 1024
#define MAX_KEY_LEN 64
#define MAX_VALUE_LEN 256

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Metadata;

static int compare_metadata(const void *a, const void *b) {
    const Metadata *ma = a;
    const Metadata *mb = b;
    return strcmp(ma->key, mb->key);
}

static void print_metadata(const Metadata *metadata) {
    printf("key: %s\n", metadata->key);
    printf("value: %s\n", metadata->value);
}

static void add_metadata(Metadata *metadata, const char *key, const char *value) {
    strncpy(metadata->key, key, MAX_KEY_LEN);
    strncpy(metadata->value, value, MAX_VALUE_LEN);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }

    Metadata *metadata = NULL;
    size_t metadata_count = 0;
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        char *key = NULL;
        char *value = NULL;
        if (sscanf(line, "%*s %ms %ms", &key, &value)!= 2) {
            fprintf(stderr, "Error: invalid metadata format on line %zu\n", metadata_count + 1);
            continue;
        }

        Metadata new_metadata = { 0 };
        add_metadata(&new_metadata, key, value);
        metadata = realloc(metadata, sizeof(Metadata) * (metadata_count + 1));
        if (metadata == NULL) {
            fprintf(stderr, "Error: out of memory\n");
            exit(1);
        }
        metadata[metadata_count] = new_metadata;
        metadata_count++;
    }

    fclose(file);

    qsort(metadata, metadata_count, sizeof(Metadata), compare_metadata);

    for (size_t i = 0; i < metadata_count; i++) {
        print_metadata(&metadata[i]);
    }

    free(metadata);
    return 0;
}