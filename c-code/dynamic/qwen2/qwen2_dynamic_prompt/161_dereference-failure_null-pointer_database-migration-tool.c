#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase() {
    int *data = NULL;
    printf("Migrating database...\n");
    // Simulate database operation
    data[0] = 1; // Dereference null pointer
}

int main() {
    migrateDatabase();
    return 0;
}
