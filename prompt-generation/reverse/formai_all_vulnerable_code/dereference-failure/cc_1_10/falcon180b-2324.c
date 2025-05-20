//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_COLUMNS 4
#define MAX_COLUMN_NAME_LENGTH 20

typedef struct {
    char name[MAX_COLUMN_NAME_LENGTH];
    int type;
    int size;
} Column;

typedef struct {
    char name[MAX_COLUMN_NAME_LENGTH];
    Column* columns;
    int num_columns;
    int num_records;
    void** records;
} Table;

void create_table(Table* table, char* name, Column* columns, int num_columns) {
    strcpy(table->name, name);
    table->columns = columns;
    table->num_columns = num_columns;
    table->num_records = 0;
    table->records = malloc(MAX_RECORDS * sizeof(void*));
}

void add_record(Table* table, void* record) {
    table->records[table->num_records++] = record;
}

void print_table(Table* table) {
    printf("Table: %s\n", table->name);
    printf("Columns:\n");
    for (int i = 0; i < table->num_columns; i++) {
        printf("%s (%d bytes)\n", table->columns[i].name, table->columns[i].size);
    }
    printf("Records:\n");
    for (int i = 0; i < table->num_records; i++) {
        for (int j = 0; j < table->num_columns; j++) {
            switch (table->columns[j].type) {
                case 'i':
                    printf("%d ", *(int*)(((char*)table->records[i]) + table->columns[j].size * j));
                    break;
                case 'f':
                    printf("%f ", *(float*)(((char*)table->records[i]) + table->columns[j].size * j));
                    break;
                case's':
                    printf("%s ", (char*)table->records[i] + table->columns[j].size * j);
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    Column columns[] = {{"id", 'i', 4}, {"name",'s', 20}, {"age", 'i', 4}};
    Table table = {"people", columns, 3, 0};

    add_record(&table, (void*)"\x01\x00\x00\x00John\x00\x1c\x00\x00");
    add_record(&table, (void*)"\x02\x00\x00\x00Jane\x00\x14\x00\x00");

    print_table(&table);

    return 0;
}