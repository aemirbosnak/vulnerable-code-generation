//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_INDEX_SIZE 1000
#define MAX_REC_SIZE 1000
#define MAX_NUM_INDEXES 10

typedef struct {
    char key[MAX_KEY_SIZE];
    int rec_size;
    int index;
} Record;

typedef struct {
    char index_name[MAX_KEY_SIZE];
    int num_indexes;
    Record records[MAX_NUM_INDEXES];
} Index;

void create_index(Index *index) {
    printf("Enter the name of the index: ");
    scanf("%s", index->index_name);
    printf("Enter the number of indexes: ");
    scanf("%d", &index->num_indexes);
}

void add_record(Index *index, Record *record) {
    printf("Enter the record key: ");
    scanf("%s", record->key);
    printf("Enter the record size: ");
    scanf("%d", &record->rec_size);
    record->index = index->num_indexes;
    index->records[index->num_indexes++] = *record;
}

void search_index(Index *index, char *key) {
    int i, j;
    for (i = 0; i < index->num_indexes; i++) {
        if (strcmp(index->records[i].key, key) == 0) {
            printf("Record found in index %s:\n", index->index_name);
            printf("Key: %s\n", index->records[i].key);
            printf("Record size: %d\n", index->records[i].rec_size);
        }
    }
}

int main() {
    Index index;
    Record record;
    char choice;
    do {
        printf("\n********* DATABASE INDEXING SYSTEM *********\n");
        printf("1. Create index\n");
        printf("2. Add record\n");
        printf("3. Search index\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
        case '1':
            create_index(&index);
            break;
        case '2':
            printf("Enter the index name: ");
            scanf("%s", index.index_name);
            add_record(&index, &record);
            break;
        case '3':
            printf("Enter the index name: ");
            scanf("%s", index.index_name);
            search_index(&index, "");
            break;
        case '4':
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}