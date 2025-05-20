//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Metadata;

void split_line(char line[], Metadata *metadata) {
    char *key, *value;
    key = strtok(line, ":");
    value = strtok(NULL, ":");
    strcpy(metadata->key, key);
    strcpy(metadata->value, value);
}

int compare_metadata(const void *a, const void *b) {
    Metadata *m1 = (Metadata *)a;
    Metadata *m2 = (Metadata *)b;
    return strcmp(m1->key, m2->key);
}

void print_metadata(Metadata *metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int num_metadata = 0;
    Metadata *metadata = NULL;

    // Open file
    file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read metadata
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        num_metadata++;
        metadata = realloc(metadata, num_metadata * sizeof(Metadata));
        split_line(line, &metadata[num_metadata - 1]);
    }

    // Sort metadata
    qsort(metadata, num_metadata, sizeof(Metadata), compare_metadata);

    // Print metadata
    for (int i = 0; i < num_metadata; i++) {
        print_metadata(&metadata[i]);
    }

    // Free memory
    free(metadata);
    fclose(file);

    return 0;
}