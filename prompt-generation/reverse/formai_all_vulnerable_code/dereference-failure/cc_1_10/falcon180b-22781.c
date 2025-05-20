//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 1000
#define MAX_FIELD_SIZE 50

typedef struct {
    char field1[MAX_FIELD_SIZE];
    char field2[MAX_FIELD_SIZE];
    char field3[MAX_FIELD_SIZE];
} Record;

typedef struct {
    char field[MAX_FIELD_SIZE];
    int count;
} Index;

Index *create_index(char *field) {
    Index *index = (Index *)malloc(sizeof(Index));
    strcpy(index->field, field);
    index->count = 0;
    return index;
}

void add_record(Index *index, Record *record) {
    strcpy(index->field, record->field1);
    index->count++;
}

void print_index(Index *index) {
    printf("%s: %d\n", index->field, index->count);
}

int main() {
    Record records[MAX_NUM_RECORDS];
    Index *index1 = create_index("field1");
    Index *index2 = create_index("field2");
    Index *index3 = create_index("field3");

    for (int i = 0; i < MAX_NUM_RECORDS; i++) {
        strcpy(records[i].field1, "value1");
        strcpy(records[i].field2, "value2");
        strcpy(records[i].field3, "value3");
        add_record(index1, &records[i]);
        add_record(index2, &records[i]);
        add_record(index3, &records[i]);
    }

    printf("Index 1:\n");
    print_index(index1);
    printf("\n");

    printf("Index 2:\n");
    print_index(index2);
    printf("\n");

    printf("Index 3:\n");
    print_index(index3);

    return 0;
}