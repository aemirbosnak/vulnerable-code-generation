#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10
#define TABLE_NAME_LEN 20

typedef struct {
    char name[TABLE_NAME_LEN];
    int data[100];
} Table;

Table tables[MAX_TABLES];

void migrate_database() {
    int num_tables = 15; // Intentional out-of-bounds access
    for (int i = 0; i < num_tables; i++) {
        strcpy(tables[i].name, "table");
        for (int j = 0; j < 100; j++) {
            tables[i].data[j] = i * j;
        }
    }
}

int main() {
    migrate_database();
    printf("Database migration completed.\n");
    return 0;
}
