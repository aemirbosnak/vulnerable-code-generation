//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

struct record {
    int id;
    char name[20];
    char email[30];
};

typedef struct {
    int index_value;
    int block_pointer;
} index_entry;

int main() {
    int records_count, index_count, block_count, block_size;
    printf("Enter number of records: ");
    scanf("%d", &records_count);
    struct record *records = (struct record*) malloc(records_count * sizeof(struct record));
    for(int i = 0; i < records_count; i++) {
        printf("Enter details for record %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &records[i].id);
        printf("Name: ");
        scanf("%s", records[i].name);
        printf("Email: ");
        scanf("%s", records[i].email);
    }

    printf("Enter number of index entries: ");
    scanf("%d", &index_count);
    index_entry *index = (index_entry*) malloc(index_count * sizeof(index_entry));
    for(int i = 0; i < index_count; i++) {
        printf("Enter index entry %d:\n", i+1);
        printf("Index value: ");
        scanf("%d", &index[i].index_value);
        printf("Block pointer: ");
        scanf("%d", &index[i].block_pointer);
    }

    printf("Enter block size: ");
    scanf("%d", &block_size);
    block_count = (records_count + block_size - 1) / block_size;
    int **blocks = (int**) malloc(block_count * sizeof(int*));
    for(int i = 0; i < block_count; i++) {
        blocks[i] = (int*) malloc(block_size * sizeof(int));
    }

    for(int i = 0; i < index_count; i++) {
        int *block = blocks[index[i].block_pointer];
        for(int j = 0; j < block_size; j++) {
            int index_value = block[j];
            for(int k = 0; k < records_count; k++) {
                if(records[k].id == index_value) {
                    printf("Found record for index %d:\n", index_value);
                    printf("Name: %s\n", records[k].name);
                    printf("Email: %s\n", records[k].email);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < block_count; i++) {
        free(blocks[i]);
    }
    free(blocks);
    free(index);
    free(records);
    return 0;
}