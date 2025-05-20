#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10

typedef struct {
    char name[256];
    int columns;
} Table;

Table tables[MAX_TABLES];

void migrate_tables() {
    int i;
    char new_data[1024];
    
    // Simulate reading data from an old database
    strcpy(tables[0].name, "users");
    tables[0].columns = 3;
    strcpy(tables[1].name, "products");
    tables[1].columns = 4;
    
    // Attempt to write data to a table that is out of bounds
    for (i = 0; i < MAX_TABLES + 1; i++) {
        sprintf(new_data, "Migrating %s", tables[i].name);
        // This will write beyond the allocated memory if i == MAX_TABLES
        memcpy(tables[i].name, new_data, strlen(new_data));
    }
}

int main() {
    migrate_tables();
    return 0;
}
