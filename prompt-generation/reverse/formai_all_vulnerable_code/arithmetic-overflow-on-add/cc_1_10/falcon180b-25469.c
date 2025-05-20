//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

typedef struct {
    char *name;
    Table *table;
} Database;

Database *create_database() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->name = "MyDatabase";
    db->table = NULL;
    return db;
}

void add_table(Database *db, char *name) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (char *)malloc(MAX_ROWS * MAX_COLS * MAX_DATA_LEN);
    table->rows = 0;
    table->cols = 0;
    db->table = table;
}

void add_column(Table *table, char *name) {
    table->cols++;
}

void add_row(Table *table) {
    table->rows++;
}

void set_data(Table *table, int row, int col, char *data) {
    int offset = (row * MAX_COLS + col) * MAX_DATA_LEN;
    memcpy(table->data + offset, data, strlen(data));
}

char *get_data(Table *table, int row, int col) {
    int offset = (row * MAX_COLS + col) * MAX_DATA_LEN;
    return table->data + offset;
}

void print_table(Table *table) {
    for (int row = 0; row < table->rows; row++) {
        for (int col = 0; col < table->cols; col++) {
            printf("%s\t", get_data(table, row, col));
        }
        printf("\n");
    }
}

int main() {
    Database *db = create_database();
    add_table(db, "MyTable");
    add_column(db->table, "Column1");
    add_column(db->table, "Column2");
    add_row(db->table);
    set_data(db->table, 0, 0, "Hello");
    set_data(db->table, 0, 1, "World");
    printf("Table data:\n");
    print_table(db->table);
    return 0;
}