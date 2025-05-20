//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key[20];
    int value;
} Record;

typedef struct {
    char key[20];
    int block_number;
} Index;

int main() {
    int num_records = 5;
    int num_blocks = 3;

    // initialize records
    Record records[num_records];
    strcpy(records[0].key, "apple");
    records[0].value = 5;
    strcpy(records[1].key, "banana");
    records[1].value = 10;
    strcpy(records[2].key, "cherry");
    records[2].value = 15;
    strcpy(records[3].key, "fig");
    records[3].value = 20;
    strcpy(records[4].key, "grape");
    records[4].value = 25;

    // initialize index
    Index index[num_records];
    strcpy(index[0].key, "apple");
    index[0].block_number = 0;
    strcpy(index[1].key, "banana");
    index[1].block_number = 1;
    strcpy(index[2].key, "cherry");
    index[2].block_number = 2;
    strcpy(index[3].key, "fig");
    index[3].block_number = 0;
    strcpy(index[4].key, "grape");
    index[4].block_number = 1;

    // search for record
    char search_key[20];
    printf("Enter the key to search for: ");
    scanf("%s", search_key);
    for(int i = 0; i < num_records; i++) {
        if(strcmp(search_key, records[i].key) == 0) {
            // found record, read from block
            int block_num = index[i].block_number;
            printf("Found record with key %s and value %d in block %d.\n", records[i].key, records[i].value, block_num);
            break;
        }
        if(i == num_records - 1) {
            printf("Record not found.\n");
        }
    }
    return 0;
}