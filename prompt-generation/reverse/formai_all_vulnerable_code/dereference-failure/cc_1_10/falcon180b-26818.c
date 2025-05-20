//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_META_KEYS 100
#define MAX_META_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} MetaData;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    int num_meta_keys = 0;
    MetaData *meta_keys = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Check for metadata
        if (line[0] == '@') {
            char *key_value_pair = strdup(line + 1);
            char *delimiter = strchr(key_value_pair, ':');

            if (delimiter == NULL) {
                printf("Error: Invalid metadata on line %d.\n", line_number);
                continue;
            }

            *delimiter = '\0';
            char *key = strdup(key_value_pair);
            char *value = strdup(delimiter + 1);

            if (num_meta_keys >= MAX_META_KEYS) {
                printf("Error: Too many metadata keys.\n");
                continue;
            }

            meta_keys = realloc(meta_keys, sizeof(MetaData) * (num_meta_keys + 1));
            meta_keys[num_meta_keys].key = key;
            meta_keys[num_meta_keys].value = value;
            num_meta_keys++;
        }

        line_number++;
    }

    fclose(file);

    // Print metadata
    if (num_meta_keys > 0) {
        printf("Metadata:\n");
        for (int i = 0; i < num_meta_keys; i++) {
            printf("%s: %s\n", meta_keys[i].key, meta_keys[i].value);
        }
    }

    return 0;
}