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
    gets(source); // Vulnerable to buffer overflow

    printf("Enter destination database path: ");
    gets(destination); // Vulnerable to buffer overflow

    printf("Migrating from %s to %s\n", source, destination);
    // Simulate migration process
    sleep(2);

    printf("Migration completed successfully.\n");
}

int main() {
    printf("Welcome to the Database Migration Tool\n");
    migrateDatabase();
    return 0;
}
