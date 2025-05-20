//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_KEY_LEN 32
#define MAX_VALUE_LEN 1024

struct metadata {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
};

struct metadata* extract_metadata(char* input_file) {
    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", input_file);
        exit(1);
    }

    struct metadata* metadata = NULL;
    char line[MAX_LINE_LEN];
    char* key = NULL;
    char* value = NULL;
    int key_len = 0;
    int value_len = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (metadata == NULL) {
            metadata = malloc(sizeof(struct metadata));
            key = strtok(line, ":");
            value = strtok(NULL, ":");
            if (key == NULL || value == NULL) {
                printf("Error: Invalid metadata format\n");
                exit(1);
            }
            strncpy(metadata->key, key, MAX_KEY_LEN);
            metadata->key[MAX_KEY_LEN - 1] = '\0';
            strncpy(metadata->value, value, MAX_VALUE_LEN);
            metadata->value[MAX_VALUE_LEN - 1] = '\0';
        } else {
            key = strtok(line, ":");
            value = strtok(NULL, ":");
            if (key == NULL || value == NULL) {
                printf("Error: Invalid metadata format\n");
                exit(1);
            }
            strncpy(metadata->key, key, MAX_KEY_LEN);
            metadata->key[MAX_KEY_LEN - 1] = '\0';
            strncpy(metadata->value, value, MAX_VALUE_LEN);
            metadata->value[MAX_VALUE_LEN - 1] = '\0';
        }
    }

    fclose(fp);
    return metadata;
}

void print_metadata(struct metadata* metadata) {
    if (metadata == NULL) {
        printf("No metadata found\n");
        return;
    }

    printf("Metadata:\n");
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    struct metadata* metadata = extract_metadata(input_file);
    print_metadata(metadata);

    return 0;
}