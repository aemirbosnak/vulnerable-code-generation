#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void migrateDatabase() {
    char source[10];
    char destination[20];

    printf("Enter source database path: ");
    scanf("%s", source);

    printf("Enter destination database path: ");
    scanf("%s", destination);

    // Simulate database migration
    printf("Migrating from %s to %s\n", source, destination);
}

int main() {
    migrateDatabase();
    return 0;
}
