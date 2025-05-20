#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(const char* input) {
    char source[10];
    char destination[20];

    printf("Migrating database from: %s\n", input);
    sscanf(input, "%s %s", source, destination);

    // Simulate database migration process
    printf("Migrating data from %s to %s...\n", source, destination);
    sleep(2); // Simulate time taken for migration

    printf("Migration completed successfully.\n");
}

int main() {
    const char* userInput = "source_database destination_database";
    migrateDatabase(userInput);
    return 0;
}
