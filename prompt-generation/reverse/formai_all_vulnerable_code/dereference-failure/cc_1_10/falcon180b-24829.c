//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUES 100

typedef struct {
    char *key;
    char *value;
} metadata_t;

int metadata_count = 0;
metadata_t *metadata_list = NULL;

void add_metadata(char *key, char *value) {
    if (metadata_count >= MAX_KEY_VALUES) {
        printf("Error: Maximum number of metadata exceeded.\n");
        exit(1);
    }

    metadata_t *new_metadata = (metadata_t*)malloc(sizeof(metadata_t));
    new_metadata->key = strdup(key);
    new_metadata->value = strdup(value);
    metadata_list[metadata_count++] = *new_metadata;
}

void print_metadata() {
    for (int i = 0; i < metadata_count; i++) {
        printf("%s: %s\n", metadata_list[i].key, metadata_list[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");
        if (key!= NULL && value!= NULL) {
            add_metadata(key, value);
        }
    }

    fclose(fp);
    print_metadata();

    return 0;
}