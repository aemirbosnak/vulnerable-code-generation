//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define BLOCK_SIZE 100

typedef struct {
    int key;
    char data[100];
} Record;

typedef struct {
    Record records[BLOCK_SIZE];
    int count;
} Block;

Block *table;
int num_blocks;
int num_records;

int compare(const void *a, const void *b) {
    Record *record1 = (Record *)a;
    Record *record2 = (Record *)b;
    return strcmp(record1->data, record2->data);
}

void create_table() {
    table = (Block *)malloc(MAX_SIZE * sizeof(Block));
    num_blocks = 0;
    num_records = 0;
}

void insert_record(int key, char *data) {
    if (num_records == MAX_SIZE) {
        printf("Table is full!\n");
        return;
    }
    if (num_blocks == 0) {
        create_table();
    }
    Record *record = (Record *)malloc(sizeof(Record));
    record->key = key;
    strcpy(record->data, data);
    table[num_blocks - 1].records[num_records++] = *record;
    free(record);
}

void search_record(int key) {
    qsort(table, num_blocks, sizeof(Block), compare);
    int i, j;
    for (i = 0; i < num_blocks; i++) {
        for (j = 0; j < table[i].count; j++) {
            if (table[i].records[j].key == key) {
                printf("Record found!\n");
                printf("Data: %s\n", table[i].records[j].data);
                return;
            }
        }
    }
    printf("Record not found!\n");
}

int main() {
    create_table();
    insert_record(1, "John");
    insert_record(2, "Doe");
    insert_record(3, "Jane");
    search_record(1);
    search_record(4);
    return 0;
}