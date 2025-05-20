//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100
#define MAX_ENTRIES 1000
#define MAX_KEY_SIZE 100

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int num_entries;
} Index;

Index* createIndex() {
    Index* index = (Index*)malloc(sizeof(Index));
    index->num_entries = 0;
    return index;
}

void addEntry(Index* index, int key, int value) {
    if (index->num_entries >= MAX_ENTRIES) {
        printf("Error: Index is full.\n");
        return;
    }
    Entry entry = {key, value};
    index->entries[index->num_entries++] = entry;
}

int searchIndex(Index* index, int key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (index->entries[i].key == key) {
            return index->entries[i].value;
        }
    }
    return -1;
}

int main() {
    Index* index = createIndex();

    addEntry(index, 1, 10);
    addEntry(index, 2, 20);
    addEntry(index, 3, 30);
    addEntry(index, 4, 40);
    addEntry(index, 5, 50);

    int value1 = searchIndex(index, 1);
    int value2 = searchIndex(index, 3);
    int value3 = searchIndex(index, 5);
    int value4 = searchIndex(index, 7);

    printf("Value for key 1: %d\n", value1);
    printf("Value for key 3: %d\n", value2);
    printf("Value for key 5: %d\n", value3);
    printf("Value for key 7: %d\n", value4);

    return 0;
}