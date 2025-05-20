//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 1024
#define DELIMITER "="

typedef struct {
    char* key;
    char* value;
} Metadata;

void metadata_free(Metadata* metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

char* metadata_extract(char* line, char* delimiter) {
    char* key = strtok(line, delimiter);
    char* value = strtok(NULL, delimiter);
    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->key = strdup(key);
    metadata->value = strdup(value);
    return metadata;
}

void metadata_print(Metadata* metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Metadata* metadata;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* delimiter = strrchr(line, ':');
        if (delimiter == NULL) {
            printf("Error: Invalid line format in file %s\n", argv[1]);
            continue;
        }
        *delimiter = '\0';
        metadata = metadata_extract(line, DELIMITER);
        metadata_print(metadata);
        metadata_free(metadata);
    }

    fclose(file);
    return 0;
}