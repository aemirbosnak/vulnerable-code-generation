//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    char name[MAX_KEY_LEN];
    int id;
} IndexItem;

typedef struct {
    int numRows;
    IndexItem* items;
} Index;

Index* createIndex(int numColumns) {
    Index* index = malloc(sizeof(Index));
    index->numRows = 0;
    index->items = malloc(sizeof(IndexItem) * numColumns);
    for (int i = 0; i < numColumns; i++) {
        index->items[i].id = -1;
        strcpy(index->items[i].name, "");
    }
    return index;
}

void addEntry(Index* index, int rowId, char* columnName, int columnId) {
    int i;
    for (i = 0; i < index->numRows; i++) {
        if (index->items[columnId].id == rowId) {
            printf("Duplicate entry for row %d in column %s\n", rowId, columnName);
            return;
        }
    }
    strcpy(index->items[columnId].name, columnName);
    index->items[columnId].id = rowId;
    index->numRows++;
}

void printIndex(Index* index) {
    printf("Index:\n");
    for (int i = 0; i < index->numRows; i++) {
        printf("Column %d: %s\n", i, index->items[i].name);
    }
}

int main() {
    Index* index = createIndex(3);
    addEntry(index, 1, "John", 0);
    addEntry(index, 2, "Doe", 0);
    addEntry(index, 3, "Jane", 0);
    addEntry(index, 4, "Doe", 0);
    printIndex(index);
    return 0;
}