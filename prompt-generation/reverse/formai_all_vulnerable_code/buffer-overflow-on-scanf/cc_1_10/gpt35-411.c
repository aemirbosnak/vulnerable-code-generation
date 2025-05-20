//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_RECORDS 100

struct record {
    char key[MAX_KEY_LEN];
    int value;
};

struct index_entry {
    char key[MAX_KEY_LEN];
    int record_num;
};

int cmp_index_entries(const void *a, const void *b) {
    return strcmp(((struct index_entry*)a)->key, ((struct index_entry*)b)->key);
}

void print_index(struct index_entry *index, int num_entries) {
    printf("Index:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("  %s: Record #%d\n", index[i].key, index[i].record_num);
    }
}

void print_records(struct record *records, int num_records) {
    printf("Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("  %s: %d\n", records[i].key, records[i].value);
    }
}

int main() {
    struct record records[MAX_RECORDS];
    int num_records = 0;
    
    char input[MAX_KEY_LEN];
    int value;
    printf("Enter key and value (enter 'quit' to stop):\n");
    scanf("%s", input);
    while (strcmp(input, "quit") != 0) {
        scanf("%d", &value);
        struct record r = { .value=value };
        strcpy(r.key, input);
        records[num_records++] = r;
        printf("Enter key and value (enter 'quit' to stop):\n");
        scanf("%s", input);
    }
    
    struct index_entry index[MAX_RECORDS];
    int num_index_entries = num_records;
    for (int i = 0; i < num_index_entries; i++) {
        strcpy(index[i].key, records[i].key);
        index[i].record_num = i;
    }
    qsort(index, num_index_entries, sizeof(struct index_entry), cmp_index_entries);
    
    printf("\n");
    print_records(records, num_records);
    printf("\n");
    print_index(index, num_index_entries);
    
    return 0;
}