//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1024

typedef struct {
    char *data;
    int rows;
    int cols;
} Data;

typedef struct {
    char *name;
    Data *data;
} Table;

Table *createTable(char *name) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->name = strdup(name);
    table->data = malloc(sizeof(Data));
    table->data->data = NULL;
    table->data->rows = 0;
    table->data->cols = 0;
    return table;
}

void deleteTable(Table *table) {
    free(table->name);
    free(table->data->data);
    free(table->data);
    free(table);
}

int insertRow(Table *table, int row, char *data) {
    int newRows = table->data->rows + 1;
    if (newRows > MAX_ROWS) {
        printf("Error: Table is full.\n");
        return 1;
    }

    int newCols = strlen(data);
    if (newCols > MAX_COLS) {
        printf("Error: Column is too wide.\n");
        return 1;
    }

    if (row < 0 || row > newRows - 1) {
        printf("Error: Invalid row number.\n");
        return 1;
    }

    char **newData = malloc(sizeof(char *) * newRows);
    for (int i = 0; i < table->data->rows; i++) {
        newData[i] = strdup(table->data->data[i]);
    }
    newData[row] = strdup(data);
    free(table->data->data);
    table->data->data = newData;
    table->data->rows = newRows;

    return 0;
}

char *getValue(Table *table, int row, int col) {
    if (row < 0 || row >= table->data->rows || col < 0 || col >= table->data->cols) {
        printf("Error: Invalid coordinates.\n");
        return NULL;
    }

    char *data = table->data->data[row];
    int len = strlen(data);
    if (col >= len) {
        printf("Error: Column is out of range.\n");
        return NULL;
    }

    char *value = malloc(sizeof(char) * (col + 1));
    strncpy(value, data + col, col + 1);
    value[col] = '\0';
    return value;
}

int main() {
    Table *table = createTable("example");
    insertRow(table, 0, "Name Age Gender");
    insertRow(table, 1, "John 25 M");
    insertRow(table, 2, "Jane 30 F");

    char *name = getValue(table, 1, 0);
    char *age = getValue(table, 1, 1);
    char *gender = getValue(table, 1, 2);

    printf("Name: %s\n", name);
    printf("Age: %s\n", age);
    printf("Gender: %s\n", gender);

    deleteTable(table);
    return 0;
}