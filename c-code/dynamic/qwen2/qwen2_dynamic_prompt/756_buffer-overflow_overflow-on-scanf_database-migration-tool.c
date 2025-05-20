#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase() {
    char source[10];
    char destination[20];

    printf("Enter source database path: ");
    scanf("%s", source);

    printf("Enter destination database path: ");
    scanf("%s", destination);

    // Simulate database migration process
    printf("Migrating from %s to %s...\n", source, destination);
    sleep(2);
    printf("Migration completed successfully.\n");
}

int main() {
    printf("Welcome to Database Migration Tool\n");
    migrateDatabase();
    return 0;
}
