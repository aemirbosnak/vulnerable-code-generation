//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

metadata_t* metadata_create(void) {
    metadata_t* metadata = malloc(sizeof(metadata_t));
    if (metadata == NULL) {
        printf("Error: Unable to allocate memory for metadata.\n");
        exit(1);
    }
    memset(metadata, 0, sizeof(metadata_t));
    return metadata;
}

void metadata_destroy(metadata_t* metadata) {
    free(metadata);
}

int metadata_add(metadata_t* metadata, const char* key, const char* value) {
    if (metadata->key[0] == '\0') {
        strncpy(metadata->key, key, MAX_KEY_LENGTH);
    } else {
        printf("Error: Metadata key already exists.\n");
        return 1;
    }
    strncpy(metadata->value, value, MAX_VALUE_LENGTH);
    return 0;
}

int metadata_get(const metadata_t* metadata, const char* key, char* value) {
    if (strcmp(metadata->key, key) == 0) {
        strncpy(value, metadata->value, MAX_VALUE_LENGTH);
        return 0;
    } else {
        printf("Error: Metadata key not found.\n");
        return 1;
    }
}

int metadata_print(const metadata_t* metadata) {
    printf("Metadata:\n");
    printf("  Key: %s\n", metadata->key);
    printf("  Value: %s\n", metadata->value);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    metadata_t* metadata = metadata_create();

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            continue;
        }
        metadata_add(metadata, key, value);
    }

    fclose(file);

    metadata_print(metadata);

    metadata_destroy(metadata);

    return 0;
}