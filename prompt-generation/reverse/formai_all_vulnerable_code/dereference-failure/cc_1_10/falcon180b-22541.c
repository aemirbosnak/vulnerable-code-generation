//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} Metadata;

void parse_metadata(char *line, Metadata *metadata) {
    char *key_value = strchr(line, ':');
    if (key_value!= NULL) {
        *key_value = '\0';
        metadata->key = strdup(line);
        metadata->value = strdup(key_value + 1);
    }
}

void print_metadata(Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

void free_metadata(Metadata *metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Metadata metadata;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_metadata(line, &metadata);
        print_metadata(&metadata);
        free_metadata(&metadata);
    }

    fclose(file);

    return 0;
}