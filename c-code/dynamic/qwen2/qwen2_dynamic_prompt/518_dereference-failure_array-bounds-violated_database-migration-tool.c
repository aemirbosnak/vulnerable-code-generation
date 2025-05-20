#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
    char name[256];
    int num_columns;
    char **columns;
} Table;

void migrate_database(Table *tables, int num_tables) {
    for (int i = 0; i <= num_tables; i++) { // Dereference failure here: accessing beyond array bounds
        printf("Migrating table: %s\n", tables[i].name);
        for (int j = 0; j < tables[i].num_columns; j++) {
            printf("Column %d: %s\n", j, tables[i].columns[j]);
        }
    }
}

int main() {
    Table tables[MAX_TABLES];

    // Initialize some tables
    strcpy(tables[0].name, "users");
    tables[0].num_columns = 3;
    tables[0].columns = malloc(3 * sizeof(char *));
    tables[0].columns[0] = strdup("id");
    tables[0].columns[1] = strdup("username");
    tables[0].columns[2] = strdup("email");

    strcpy(tables[1].name, "posts");
    tables[1].num_columns = 4;
    tables[1].columns = malloc(4 * sizeof(char *));
    tables[1].columns[0] = strdup("id");
    tables[1].columns[1] = strdup("user_id");
    tables[1].columns[2] = strdup("content");
    tables[1].columns[3] = strdup("timestamp");

    migrate_database(tables, 2);

    // Free allocated memory
    for (int i = 0; i < MAX_TABLES; i++) {
        free(tables[i].columns);
    }

    return 0;
}
