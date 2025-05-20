//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IndexEntry {
    char* key;
    int value;
};

struct Index {
    int size;
    struct IndexEntry* entries;
};

struct Index* create_index() {
    struct Index* index = malloc(sizeof(struct Index));
    index->size = 0;
    index->entries = malloc(sizeof(struct IndexEntry) * 10);
    return index;
}

void add_entry(struct Index* index, char* key, int value) {
    if (index->size >= 10) {
        printf("Index is full, unable to add entry\n");
        return;
    }
    index->entries[index->size].key = key;
    index->entries[index->size].value = value;
    index->size++;
}

int find_entry(struct Index* index, char* key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return index->entries[i].value;
        }
    }
    return -1;
}

void delete_entry(struct Index* index, char* key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            for (int j = i + 1; j < index->size; j++) {
                index->entries[j - 1] = index->entries[j];
            }
            index->size--;
            break;
        }
    }
}

int main() {
    struct Index* index = create_index();
    add_entry(index, "apple", 10);
    add_entry(index, "banana", 20);
    add_entry(index, "cherry", 30);
    printf("Value for apple: %d\n", find_entry(index, "apple"));
    printf("Value for banana: %d\n", find_entry(index, "banana"));
    printf("Value for cherry: %d\n", find_entry(index, "cherry"));
    delete_entry(index, "apple");
    printf("Value for apple: %d\n", find_entry(index, "apple"));
    return 0;
}