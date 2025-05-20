#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void migrate_database(char *db_path, char *new_db_path) {
    char buffer[MAX_SIZE];
    FILE *file = fopen(db_path, "r");

    if (!file) {
        printf("Error: Unable to open the database file.\n");
        return;
    }

    printf("Migrating data from %s to %s...\n", db_path, new_db_path);

    while (fgets(buffer, MAX_SIZE, file)) {
        // Intentionally vulnerable to buffer overflow
        gets(buffer);

        // Write the data to the new database (simulated)
        printf("Writing to new database: %s\n", buffer);
    }

    fclose(file);
    printf("Migration completed successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate <old_database> <new_database>\n");
        return 1;
    }

    migrate_database(argv[1], argv[2]);
    return 0;
}
