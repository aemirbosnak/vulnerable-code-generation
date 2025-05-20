//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_ROWS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int type;
    int size;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
    int num_rows;
    char **data;
} table_t;

table_t *create_table(int num_fields) {
    table_t *table = (table_t *)malloc(sizeof(table_t));
    table->fields = (field_t *)malloc(sizeof(field_t) * num_fields);
    table->num_fields = num_fields;
    table->num_rows = 0;
    table->data = (char **)malloc(sizeof(char *) * num_fields);
    for (int i = 0; i < num_fields; i++) {
        table->data[i] = (char *)malloc(MAX_DATA_SIZE);
    }
    return table;
}

void add_row(table_t *table, char **data) {
    for (int i = 0; i < table->num_fields; i++) {
        strcpy(table->data[i] + (table->num_rows * table->fields[i].size), data[i]);
    }
    table->num_rows++;
}

void free_table(table_t *table) {
    for (int i = 0; i < table->num_fields; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table->fields);
    free(table);
}

int main() {
    table_t *table = create_table(3);
    field_t fields[] = {{"name", 1, 50}, {"age", 2, 3}, {"gender", 3, 6}};
    table->fields = fields;
    add_row(table, (char **)malloc(sizeof(char *) * 3));
    strcpy(table->data[0], "John");
    strcpy(table->data[1], "25");
    strcpy(table->data[2], "Male");
    add_row(table, (char **)malloc(sizeof(char *) * 3));
    strcpy(table->data[0], "Jane");
    strcpy(table->data[1], "30");
    strcpy(table->data[2], "Female");
    free_table(table);
    return 0;
}