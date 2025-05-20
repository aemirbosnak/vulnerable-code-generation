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
    // Simulate some operations on the table
    printf("Migrating table: %s\n", table->data);
}

int main() {
    Table *tables = (Table *)malloc(2 * sizeof(Table));
    if (!tables) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    tables[0].data = strdup("old_table");
    tables[1].data = strdup("new_table");

    migrateTable(&tables[0]);
    migrateTable(&tables[1]);

    // Free the memory
    free(tables[0].data);
    free(tables[1].data);

    // Use-after-free vulnerability
    printf("Data from freed table: %s\n", tables[0].data); // Use-after-free

    free(tables); // Double free

    return 0;
}
