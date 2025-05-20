//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_entry;

typedef struct {
    metadata_entry* entries;
    int entry_count;
} metadata_table;

metadata_entry* create_metadata_entry(const char* key, const char* value) {
    metadata_entry* entry = malloc(sizeof(metadata_entry));

    strncpy(entry->key, key, MAX_KEY_SIZE);
    strncpy(entry->value, value, MAX_VALUE_SIZE);

    return entry;
}

metadata_table* create_metadata_table() {
    metadata_table* table = malloc(sizeof(metadata_table));

    table->entries = NULL;
    table->entry_count = 0;

    return table;
}

void add_metadata_entry(metadata_table* table, const char* key, const char* value) {
    metadata_entry* entry = create_metadata_entry(key, value);

    table->entries = realloc(table->entries, sizeof(metadata_entry) * (table->entry_count + 1));
    table->entries[table->entry_count++] = *entry;

    free(entry);
}

void print_metadata_table(metadata_table* table) {
    for (int i = 0; i < table->entry_count; i++) {
        printf("%s: %s\n", table->entries[i].key, table->entries[i].value);
    }
}

metadata_table* read_metadata_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }

    metadata_table* table = create_metadata_table();

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char* key_value_pair = strtok(line, ":");
        if (key_value_pair == NULL) {
            continue;
        }

        char* key = strtok(key_value_pair, " ");
        char* value = strtok(NULL, " ");

        if (key == NULL || value == NULL) {
            continue;
        }

        add_metadata_entry(table, key, value);
    }

    fclose(file);

    return table;
}

int main() {
    metadata_table* table = read_metadata_from_file("metadata.txt");

    if (table!= NULL) {
        print_metadata_table(table);
    }

    return 0;
}