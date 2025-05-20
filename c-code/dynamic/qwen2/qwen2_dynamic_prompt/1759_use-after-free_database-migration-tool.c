#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
} Table;

void migrateTable(Table *table) {
    // Simulate data migration
    table->data = (char *)realloc(table->data, 1024);
}

int main() {
    Table table;
    table.data = (char *)malloc(512);

    strcpy(table.data, "Initial Data");

    printf("Before Migration: %s\n", table.data);

    migrateTable(&table);

    printf("After Migration: %s\n", table.data);

    // Use-after-free vulnerability
    free(table.data);
    table.data[0] = 'X'; // Undefined behavior

    return 0;
}
