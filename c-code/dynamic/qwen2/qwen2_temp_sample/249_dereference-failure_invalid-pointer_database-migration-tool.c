#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
    char name[20];
    int data;
} Table;

Table* tables[MAX_TABLES];
int table_count = 0;

void create_table(const char* name, int data) {
    if (table_count >= MAX_TABLES) {
        printf("Maximum number of tables reached!\n");
        return;
    }
    tables[table_count] = (Table*)malloc(sizeof(Table));
    if (!tables[table_count]) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(tables[table_count]->name, name);
    tables[table_count]->data = data;
    table_count++;
}

void drop_table(int index) {
    if (index < 0 || index >= table_count) {
        printf("Invalid table index!\n");
        return;
    }
    free(tables[index]);
    for (int i = index; i < table_count - 1; i++) {
        tables[i] = tables[i + 1];
    }
    table_count--;
}

void print_tables() {
    for (int i = 0; i < table_count; i++) {
        printf("%s: %d\n", tables[i]->name, tables[i]->data);
    }
}

int main() {
    create_table("users", 100);
    create_table("products", 200);

    print_tables();

    // Intentional dereference failure
    int invalid_index = 10;
    drop_table(invalid_index); // Invalid index to demonstrate dereference failure

    print_tables();

    for (int i = 0; i < table_count; i++) {
        free(tables[i]);
    }

    return 0;
}
