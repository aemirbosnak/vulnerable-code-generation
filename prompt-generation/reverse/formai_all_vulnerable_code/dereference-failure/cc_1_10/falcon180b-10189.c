//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000
#define MAX_INDEX_SIZE 1000

typedef struct {
    char *entry;
    int index;
} entry_t;

typedef struct {
    entry_t *entries;
    int num_entries;
    int index_size;
} index_t;

void init_index(index_t *index) {
    index->entries = NULL;
    index->num_entries = 0;
    index->index_size = 0;
}

int add_entry(index_t *index, char *entry) {
    int index_pos = index->index_size;
    while (index_pos > 0 && strcmp(index->entries[index_pos-1].entry, entry) > 0) {
        index_pos--;
    }
    index->entries[index_pos] = (entry_t) {
       .entry = strdup(entry),
       .index = index_pos
    };
    index->num_entries++;
    if (index->num_entries > index->index_size) {
        index->index_size = index->num_entries;
    }
    return index_pos;
}

void print_entries(index_t *index) {
    for (int i = 0; i < index->num_entries; i++) {
        printf("%s\n", index->entries[i].entry);
    }
}

int main() {
    index_t index;
    init_index(&index);
    add_entry(&index, "apple");
    add_entry(&index, "banana");
    add_entry(&index, "cherry");
    add_entry(&index, "date");
    add_entry(&index, "elderberry");
    add_entry(&index, "fig");
    add_entry(&index, "grape");
    add_entry(&index, "honeydew");
    add_entry(&index, "kiwi");
    add_entry(&index, "lemon");
    print_entries(&index);
    return 0;
}