#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_TABLES 10
#define TABLE_NAME_LENGTH 20

typedef struct {
    char name[TABLE_NAME_LENGTH];
    int data[100];
} Table;

Table tables[MAX_TABLES];

void migrate_database() {
    int num_tables = 15; // Intentional out-of-bounds access
    for (int i = 0; i <= num_tables; i++) { // Out-of-bounds loop
        strcpy(tables[i].name, "table"); // Potential buffer overflow
        for (int j = 0; j < 100; j++) {
            tables[i].data[j] = j * i; // Arbitrary data manipulation
        }
    }
}

int main() {
    migrate_database();
    return 0;
}
