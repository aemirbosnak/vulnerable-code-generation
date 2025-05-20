#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Table {
    char name[20];
    int rows;
    int columns;
    void** data;
} Table;

Table* createTable(char* name, int rows, int columns) {
    Table* table = (Table*)malloc(sizeof(Table));
    strcpy(table->name, name);
    table->rows = rows;
    table->columns = columns;
    table->data = (void*)malloc(rows * columns * sizeof(void*));

    return table;
}

void insertData(Table* table, int row, int column, void* data) {
    table->data[row * table->columns + column] = data;
}

void printTable(Table* table) {
    printf("%s:\n", table->name);
    for (int i = 0; i < table->rows; ++i) {
        for (int j = 0; j < table->columns; ++j) {
            printf("%p ", table->data[i * table->columns + j]);
        }
        printf("\n");
    }
}

int main() {
    Table* customers = createTable("Customers", 1000000, 10);
    Table* orders = createTable("Orders", 1000000, 5);

    for (int i = 0; i < 1000000; ++i) {
        insertData(customers, i, 0, &i);
        insertData(orders, i, 0, &i);
    }

    printf("Customers:\n");
    printTable(customers);

    printf("Orders:\n");
    printTable(orders);

    return 0;
}
