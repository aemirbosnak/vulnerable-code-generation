#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
    char *name;
    int size;
} Table;

Table* tables[MAX_TABLES];
int table_count = 0;

void create_table(const char *name, int size) {
    if (table_count >= MAX_TABLES) {
        printf("Error: Maximum number of tables reached.\n");
        return;
    }
    tables[table_count] = malloc(sizeof(Table));
    tables[table_count]->name = strdup(name);
    tables[table_count]->size = size;
    table_count++;
}

void drop_table(int index) {
    if (index < 0 || index >= table_count) {
        printf("Error: Invalid table index.\n");
        return;
    }
    free(tables[index]->name);
    free(tables[index]);
    for (int i = index; i < table_count - 1; i++) {
        tables[i] = tables[i + 1];
    }
    table_count--;
}

void rename_table(int index, const char *new_name) {
    if (index < 0 || index >= table_count) {
        printf("Error: Invalid table index.\n");
        return;
    }
    free(tables[index]->name);
    tables[index]->name = strdup(new_name);
}

void print_tables() {
    for (int i = 0; i < table_count; i++) {
        printf("Table %d: %s (%d)\n", i, tables[i]->name, tables[i]->size);
    }
}

int main() {
    create_table("users", 100);
    create_table("products", 200);

    print_tables();

    drop_table(0);

    // Use-after-free vulnerability
    rename_table(0, "new_users");

    print_tables();

    return 0;
}
