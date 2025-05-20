#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10
#define MAX_COLUMNS 100
#define MAX_LENGTH 255

typedef struct Table {
    char name[MAX_LENGTH];
    int num_columns;
    char **columns;
} Table;

Table tables[MAX_TABLES];
int table_count = 0;

void create_table(char *table_name, int num_columns, char **column_names) {
    Table *new_table = &tables[table_count];
    strcpy(new_table->name, table_name);
    new_table->num_columns = num_columns;
    new_table->columns = (char **)malloc(num_columns * sizeof(char *));

    for (int i = 0; i < num_columns; ++i) {
        new_table->columns[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
        strcpy(new_table->columns[i], column_names[i]);
    }

    table_count++;
}

int main() {
    create_table("users", 2, (char*[]){"id", "username"});
    create_table("posts", 3, (char*[]){"id", "user_id", "content"});

    Table *invalid_table = tables - table_count; // Dereference failure intentionally introduced

    printf("%s\n", invalid_table->name); // Accessing invalid memory

    return 0;
}
