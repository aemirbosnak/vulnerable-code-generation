//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 50
#define MAX_VALUE_LEN 500
#define MAX_NUM_ROWS 1000
#define MAX_NUM_COLS 50

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Row;

typedef struct {
    char *headers[MAX_NUM_COLS];
    Row rows[MAX_NUM_ROWS];
    int numRows;
    int numCols;
} Table;

Table *createTable() {
    Table *table = (Table *)malloc(sizeof(Table));
    if (table == NULL) {
        printf("Error: Could not allocate memory for table.\n");
        exit(1);
    }
    table->numRows = 0;
    table->numCols = 0;
    return table;
}

void addRow(Table *table, char *key, char *value) {
    if (table->numRows >= MAX_NUM_ROWS) {
        printf("Error: Table is full.\n");
        exit(1);
    }
    Row row;
    strcpy(row.key, key);
    strcpy(row.value, value);
    table->rows[table->numRows] = row;
    table->numRows++;
}

void addColumn(Table *table, char *header) {
    if (table->numCols >= MAX_NUM_COLS) {
        printf("Error: Table has too many columns.\n");
        exit(1);
    }
    table->headers[table->numCols] = (char *)malloc(sizeof(char) * (strlen(header) + 1));
    if (table->headers[table->numCols] == NULL) {
        printf("Error: Could not allocate memory for column header.\n");
        exit(1);
    }
    strcpy(table->headers[table->numCols], header);
    table->numCols++;
}

void printTable(Table *table) {
    printf("\n");
    for (int i = 0; i < table->numCols; i++) {
        printf("%-20s", table->headers[i]);
    }
    printf("\n");
    for (int i = 0; i < table->numRows; i++) {
        for (int j = 0; j < table->numCols; j++) {
            printf("%-20s", table->rows[i].value);
        }
        printf("\n");
    }
}

int main() {
    Table *table = createTable();
    addColumn(table, "Name");
    addColumn(table, "Age");
    addColumn(table, "Gender");
    addRow(table, "John", "25");
    addRow(table, "Jane", "30");
    addRow(table, "Bob", "40");
    printTable(table);
    return 0;
}