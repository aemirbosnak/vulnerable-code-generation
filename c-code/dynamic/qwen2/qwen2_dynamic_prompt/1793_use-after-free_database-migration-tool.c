#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} Table;

Table* create_table(const char *name) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = strdup(name);
    return table;
}

void drop_table(Table *table) {
    if (table != NULL) {
        free(table->data);
        free(table);
    }
}

void rename_table(Table *table, const char *new_name) {
    if (table != NULL && new_name != NULL) {
        free(table->data);
        table->data = strdup(new_name);
    }
}

int main() {
    Table *table = create_table("old_table");
    printf("Original table name: %s\n", table->data);

    rename_table(table, "new_table");
    printf("Renamed table name: %s\n", table->data);

    // Use-after-free vulnerability
    printf("Accessing freed memory: %s\n", table->data); // Undefined behavior

    drop_table(table);

    return 0;
}
