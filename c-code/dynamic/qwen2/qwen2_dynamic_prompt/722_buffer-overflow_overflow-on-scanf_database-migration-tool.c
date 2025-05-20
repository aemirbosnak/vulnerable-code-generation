#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

void migrateDatabase() {
    char oldName[MAX_NAME_LENGTH];
    char newName[MAX_NAME_LENGTH];

    printf("Enter old database name: ");
    scanf("%s", oldName);

    printf("Enter new database name: ");
    scanf("%s", newName);

    // Simulate database migration
    printf("Migrating from %s to %s...\n", oldName, newName);
}

int main() {
    printf("Welcome to the Database Migration Tool\n");
    migrateDatabase();
    return 0;
}
