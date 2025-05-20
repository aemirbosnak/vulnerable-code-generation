//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_entry_t;

metadata_entry_t *metadata_entries;
int num_metadata_entries;

void add_metadata_entry(char *key, char *value) {
    metadata_entry_t *new_entry = (metadata_entry_t *) malloc(sizeof(metadata_entry_t));
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    metadata_entries = (metadata_entry_t *) realloc(metadata_entries, sizeof(metadata_entry_t) * ++num_metadata_entries);
    metadata_entries[num_metadata_entries - 1] = *new_entry;
}

void print_metadata() {
    for (int i = 0; i < num_metadata_entries; i++) {
        printf("%s: %s\n", metadata_entries[i].key, metadata_entries[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *key, *value;

    metadata_entries = (metadata_entry_t *) malloc(sizeof(metadata_entry_t));
    num_metadata_entries = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line[0] == '#') {
            key = strtok(line, ":");
            value = strtok(NULL, ":");
            add_metadata_entry(key, value);
        }
    }

    print_metadata();

    for (int i = 0; i < num_metadata_entries; i++) {
        free(metadata_entries[i].key);
        free(metadata_entries[i].value);
    }
    free(metadata_entries);

    return 0;
}