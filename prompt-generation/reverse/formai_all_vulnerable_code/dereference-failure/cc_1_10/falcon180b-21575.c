//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 100

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

void read_metadata(metadata_t *metadata, FILE *file) {
    char line[MAX_LINE_SIZE];
    metadata->key[0] = '\0';
    metadata->value[0] = '\0';

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int key_size = strlen(line);
        if (key_size > MAX_KEY_SIZE) {
            printf("Error: Key is too long.\n");
            exit(1);
        }
        strcpy(metadata->key, line);

        int value_size = strlen(line);
        if (value_size > MAX_VALUE_SIZE) {
            printf("Error: Value is too long.\n");
            exit(1);
        }
        strcpy(metadata->value, line);
        break;
    }
}

void print_metadata(metadata_t *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

int main() {
    metadata_t metadata;
    FILE *file = fopen("metadata.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open metadata file.\n");
        exit(1);
    }

    read_metadata(&metadata, file);
    print_metadata(&metadata);

    fclose(file);

    return 0;
}