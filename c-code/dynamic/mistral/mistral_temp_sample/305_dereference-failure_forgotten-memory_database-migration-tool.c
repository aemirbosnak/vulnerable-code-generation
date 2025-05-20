#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 100

typedef struct {
    char name[50];
    char* columns;
    int num_columns;
} Table;

Table* create_table(char* table_name, char* columns_str) {
    Table* new_table = (Table*) malloc(sizeof(Table));
    strcpy(new_table->name, table_name);
    new_table->num_columns = 0;

    char* token = strtok(columns_str, ",");
    while (token != NULL) {
        new_table->columns = (char*) realloc(new_table->columns, sizeof(char) * (new_table->num_columns + 1));
        strcpy(new_table->columns + new_table->num_columns, token);
        new_table->num_columns++;

        token = strtok(NULL, ",");
    }

    return new_table;
}

void print_table(Table* table) {
    printf("Table: %s\n", table->name);
    printf("Columns: ");
    for (int i = 0; i < table->num_columns; i++) {
        printf("%s%s%s", i == 0 ? "" : ", ", table->columns[i], i == table->num_columns - 1 ? "\n" : "");
    }
}

int main() {
    Table* users_table = create_table("users", "name,email,password");
    print_table(users_table);

    free(users_table->columns); // Do not free the memory allocated for users_table struct itself, leading to a dereference failure.

    return 0;
}
