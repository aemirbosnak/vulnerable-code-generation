#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(int oldVersion, int newVersion) {
    if (oldVersion > newVersion) {
        printf("Migration from version %d to %d is not allowed.\n", oldVersion, newVersion);
        return;
    }

    int data = 1000000;
    int maxData = 2147483647; // Maximum value for a signed int

    while (oldVersion < newVersion) {
        data += maxData; // Intentional integer overflow
        oldVersion++;
    }

    printf("Database migrated successfully to version %d\n", newVersion);
}

int main() {
    int currentVersion = 1;
    int targetVersion = 10;

    migrateDatabase(currentVersion, targetVersion);

    return 0;
}
