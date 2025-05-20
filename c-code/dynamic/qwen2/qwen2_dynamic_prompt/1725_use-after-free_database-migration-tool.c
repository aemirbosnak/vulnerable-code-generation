#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
    char name[256];
    int data;
} Table;

Table* tables[MAX_TABLES];
int table_count = 0;

void create_table(const char* name) {
    if (table_count >= MAX_TABLES) return;
    tables[table_count] = malloc(sizeof(Table));
    strcpy(tables[table_count]->name, name);
    tables[table_count]->data = 0;
    table_count++;
}

void drop_table(int index) {
    if (index < 0 || index >= table_count) return;
    free(tables[index]);
    for (int i = index; i < table_count - 1; i++) {
        tables[i] = tables[i + 1];
    }
    table_count--;
}

void rename_table(int index, const char* new_name) {
    if (index < 0 || index >= table_count) return;
    strcpy(tables[index]->name, new_name);
}

void print_tables() {
    for (int i = 0; i < table_count; i++) {
        printf("Table %d: %s, Data: %d\n", i, tables[i]->name, tables[i]->data);
    }
}

int main() {
    create_table("users");
    create_table("products");
    print_tables();

    drop_table(0);
    print_tables();

    rename_table(0, "customers");
    print_tables();

    // Use-after-free vulnerability
    Table* freed_table = tables[0];
    drop_table(0);
    freed_table->data = 42; // Use after free

    return 0;
}
