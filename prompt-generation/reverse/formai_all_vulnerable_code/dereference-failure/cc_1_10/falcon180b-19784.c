//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 1024
#define MAX_NUM_KEYS 100

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int num_pairs;
} Metadata;

void init_metadata(Metadata *metadata) {
    metadata->pairs = NULL;
    metadata->num_pairs = 0;
}

void add_key_value(Metadata *metadata, char *key, char *value) {
    if (metadata->num_pairs >= MAX_NUM_KEYS) {
        printf("Error: Maximum number of key-value pairs reached.\n");
        return;
    }

    KeyValuePair *pair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    pair->key = strdup(key);
    pair->value = strdup(value);

    metadata->pairs = (KeyValuePair*) realloc(metadata->pairs, sizeof(KeyValuePair) * (metadata->num_pairs + 1));
    metadata->pairs[metadata->num_pairs++] = *pair;
}

void print_metadata(Metadata *metadata) {
    printf("Metadata:\n");
    for (int i = 0; i < metadata->num_pairs; i++) {
        printf("Key: %s\nValue: %s\n", metadata->pairs[i].key, metadata->pairs[i].value);
    }
}

int main() {
    Metadata metadata;
    init_metadata(&metadata);

    add_key_value(&metadata, "Author", "John Doe");
    add_key_value(&metadata, "Title", "The Catcher in the Rye");
    add_key_value(&metadata, "Year", "1951");
    add_key_value(&metadata, "Genre", "Fiction");

    print_metadata(&metadata);

    return 0;
}