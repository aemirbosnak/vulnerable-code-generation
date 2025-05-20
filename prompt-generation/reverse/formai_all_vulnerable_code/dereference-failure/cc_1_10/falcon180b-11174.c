//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} Metadata;

Metadata *metadata_new(void) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->key = NULL;
    metadata->value = NULL;
    return metadata;
}

void metadata_free(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

char *metadata_value(Metadata *metadata, char *key) {
    if (metadata->key && strcmp(metadata->key, key) == 0) {
        return metadata->value;
    }
    return NULL;
}

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    Metadata *metadata = NULL;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: failed to open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        key = line;
        value = strchr(line, ':');
        if (value!= NULL) {
            *value = '\0';
            value++;
            while (isspace(*value)) {
                value++;
            }
        } else {
            value = "";
        }
        metadata_free(metadata);
        metadata = metadata_new();
        metadata->key = strdup(key);
        metadata->value = strdup(value);
        printf("%s: %s\n", metadata->key, metadata->value);
    }

    fclose(file);
    return 0;
}