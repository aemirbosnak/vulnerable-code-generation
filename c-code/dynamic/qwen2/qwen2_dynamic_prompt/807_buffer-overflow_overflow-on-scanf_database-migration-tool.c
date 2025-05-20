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

    printf("Enter source database path: ");
    scanf("%s", source);

    printf("Enter destination database path: ");
    scanf("%s", destination);

    // Simulate database migration
    strcpy(destination, source);
    strcat(destination, "_backup");

    printf("Migrating from %s to %s\n", source, destination);
}

int main() {
    migrateDatabase();
    return 0;
}
