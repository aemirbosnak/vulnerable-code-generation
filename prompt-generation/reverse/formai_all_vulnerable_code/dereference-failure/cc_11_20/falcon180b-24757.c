//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    metadata_t *metadata = NULL;
    int metadata_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (line[0] == '#') {
            if (metadata == NULL) {
                metadata = malloc(sizeof(metadata_t));
                metadata->name = strdup(line + 1);
                metadata->value = NULL;
                metadata_count++;
            } else {
                if (metadata->value == NULL) {
                    metadata->value = strdup(line + 1);
                } else {
                    printf("Warning: multiple values for metadata '%s'\n", metadata->name);
                }
            }
        } else if (metadata!= NULL) {
            if (metadata->value == NULL) {
                metadata->value = strdup(line);
            } else {
                printf("Warning: multiple values for metadata '%s'\n", metadata->name);
            }
        }
    }

    if (metadata!= NULL) {
        metadata->value = strdup("");
    }

    fclose(input_file);

    printf("Found %d metadata entries:\n", metadata_count);

    for (int i = 0; i < metadata_count; i++) {
        metadata_t *current_metadata = metadata + i;
        printf("%s: %s\n", current_metadata->name, current_metadata->value);
    }

    for (int i = 0; i < metadata_count; i++) {
        free(metadata[i].name);
        free(metadata[i].value);
    }
    free(metadata);

    return 0;
}