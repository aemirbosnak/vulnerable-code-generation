#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void migrateDatabase() {
    char source[BUFFER_SIZE];
    char destination[BUFFER_SIZE];

    printf("Enter source database name: ");
    scanf("%s", source);

    printf("Enter destination database name: ");
    scanf("%s", destination);

    // Simulate database migration logic
    strcpy(source, "migrated_");
    strcat(destination, "_backup");

    printf("Migrating data from %s to %s\n", source, destination);
}

int main() {
    printf("Welcome to the Database Migration Tool!\n");
    migrateDatabase();
    return 0;
}
