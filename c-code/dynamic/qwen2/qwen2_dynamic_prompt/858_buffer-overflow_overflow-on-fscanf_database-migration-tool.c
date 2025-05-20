#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

void migrateDatabase() {
    char oldName[MAX_NAME_LENGTH];
    char newName[MAX_NAME_LENGTH];

    printf("Enter old database name: ");
    if (fscanf(stdin, "%19s", oldName) != 1) {
        fprintf(stderr, "Error reading old database name.\n");
        return;
    }

    printf("Enter new database name: ");
    if (fscanf(stdin, "%19s", newName) != 1) {
        fprintf(stderr, "Error reading new database name.\n");
        return;
    }

    // Simulate database migration
    printf("Migrating from %s to %s...\n", oldName, newName);
    sleep(2); // Simulate time taken for migration

    printf("Migration successful!\n");
}

int main() {
    migrateDatabase();
    return 0;
}
