//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

void extract_metadata(const char* filename, Metadata* metadata) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (sscanf(line, "%s: %s", key, value) == 2) {
            strcpy(metadata->key, key);
            strcpy(metadata->value, value);
            return;
        }
    }

    fprintf(stderr, "No metadata found in file: %s\n", filename);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    Metadata metadata;
    extract_metadata(argv[1], &metadata);

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    fprintf(output_file, "Metadata for file: %s\n", argv[1]);
    fprintf(output_file, "-------------------------\n");
    fprintf(output_file, "Key: %s\n", metadata.key);
    fprintf(output_file, "Value: %s\n", metadata.value);

    fclose(output_file);
    return 0;
}