//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LEN 100

// Define the structure for a database table
typedef struct {
    char name[MAX_DATA_LEN];
    int id;
    float value;
} Record;

// Define the structure for a database table
typedef struct {
    char name[MAX_DATA_LEN];
    int num_rows;
    int num_cols;
    Record **data;
} Table;

// Function to create a new table
Table* createTable(char *name, int num_rows, int num_cols) {
    Table *table = (Table*) malloc(sizeof(Table));
    strcpy(table->name, name);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (Record**) malloc(num_rows * sizeof(Record*));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (Record*) malloc(num_cols * sizeof(Record));
    }
    return table;
}

// Function to insert a record into a table
void insertRecord(Table *table, char *name, int id, float value) {
    Record *record = (Record*) malloc(sizeof(Record));
    strcpy(record->name, name);
    record->id = id;
    record->value = value;
    table->data[table->num_rows - 1][table->num_cols - 1] = *record;
}

// Function to print a table
void printTable(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Columns: %d\n", table->num_cols);
    printf("Rows: %d\n", table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s %d %.2f\n", table->data[i][j].name, table->data[i][j].id, table->data[i][j].value);
        }
    }
}

int main() {
    Table *table = createTable("MyTable", 3, 3);
    insertRecord(table, "John", 1, 25.5);
    insertRecord(table, "Jane", 2, 30.0);
    insertRecord(table, "Bob", 3, 35.5);
    printTable(table);
    return 0;
}