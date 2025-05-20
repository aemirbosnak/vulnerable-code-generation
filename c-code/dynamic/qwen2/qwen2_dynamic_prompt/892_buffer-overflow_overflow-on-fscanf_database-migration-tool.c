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
        exit(EXIT_FAILURE);
    }

    printf("Enter new database name: ");
    if (fscanf(stdin, "%19s", newName) != 1) {
        fprintf(stderr, "Error reading new database name.\n");
        exit(EXIT_FAILURE);
    }

    // Simulate database migration
    printf("Migrating from %s to %s...\n", oldName, newName);

    // Vulnerability: No bounds checking on user input
    FILE *oldFile = fopen(oldName, "r");
    if (!oldFile) {
        perror("Failed to open old database file");
        return;
    }

    FILE *newFile = fopen(newName, "w");
    if (!newFile) {
        perror("Failed to create new database file");
        fclose(oldFile);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), oldFile)) {
        fputs(line, newFile);
    }

    fclose(oldFile);
    fclose(newFile);
}

int main() {
    migrateDatabase();
    return 0;
}
