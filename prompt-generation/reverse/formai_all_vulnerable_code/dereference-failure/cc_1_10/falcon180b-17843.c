//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    char *value;
} metadata_t;

metadata_t *metadata_extract(char *input) {
    metadata_t *result = NULL;
    char *key = NULL;
    char *value = NULL;
    char *token = NULL;
    int key_len = 0;
    int value_len = 0;
    int i = 0;

    result = malloc(sizeof(metadata_t));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    key = malloc(MAX_SIZE);
    value = malloc(MAX_SIZE);

    token = strtok(input, ":");
    while (token!= NULL) {
        if (i == 0) {
            key_len = strlen(token);
            if (key_len >= MAX_SIZE) {
                fprintf(stderr, "Key too long.\n");
                exit(1);
            }
            strcpy(key, token);
        } else {
            value_len = strlen(token);
            if (value_len >= MAX_SIZE) {
                fprintf(stderr, "Value too long.\n");
                exit(1);
            }
            strcpy(value, token);
            break;
        }

        i++;
        token = strtok(NULL, ":");
    }

    result->key = key;
    result->value = value;

    return result;
}

void metadata_print(metadata_t *metadata) {
    printf("Key: %s\n", metadata->key);
    printf("Value: %s\n", metadata->value);
}

void metadata_destroy(metadata_t *metadata) {
    free(metadata->key);
    free(metadata->value);
    free(metadata);
}

int main() {
    char *input = "Author: John Doe";
    metadata_t *metadata = metadata_extract(input);

    if (metadata!= NULL) {
        metadata_print(metadata);
        metadata_destroy(metadata);
    }

    return 0;
}