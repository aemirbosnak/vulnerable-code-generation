//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    typedef struct {
        char* key;
        int value;
    } index_entry;

    typedef struct {
        index_entry* entries;
        int num_entries;
        int capacity;
    } index_table;

    void index_table_init(index_table* table, int capacity) {
        table->entries = (index_entry*)malloc(sizeof(index_entry) * capacity);
        table->num_entries = 0;
        table->capacity = capacity;
    }

    void index_table_insert(index_table* table, char* key, int value) {
        if (table->num_entries == table->capacity) {
            // Handle capacity overflow
            return;
        }
        index_entry entry = { key, value };
        table->entries[table->num_entries] = entry;
        table->num_entries++;
    }

    int index_table_lookup(index_table* table, char* key) {
        for (int i = 0; i < table->num_entries; i++) {
            if (strcmp(table->entries[i].key, key) == 0) {
                return table->entries[i].value;
            }
        }
        return -1;
    }

    void index_table_free(index_table* table) {
        free(table->entries);
        table->num_entries = 0;
        table->capacity = 0;
    }

    int main() {
        index_table table;
        index_table_init(&table, 10);
        index_table_insert(&table, "key1", 1);
        index_table_insert(&table, "key2", 2);
        index_table_insert(&table, "key3", 3);
        printf("%d\n", index_table_lookup(&table, "key2"));
        index_table_free(&table);
        return 0;
    }