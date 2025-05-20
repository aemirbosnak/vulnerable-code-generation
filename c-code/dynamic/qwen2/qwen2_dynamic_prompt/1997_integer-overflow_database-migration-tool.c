#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(int oldVersion, int newVersion) {
    if (oldVersion > newVersion) {
        printf("Downgrading from version %d to %d\n", oldVersion, newVersion);
    } else {
        printf("Upgrading from version %d to %d\n", oldVersion, newVersion);
    }
}

int main() {
    int currentVersion = 1;
    int targetVersion = 2147483647; // Maximum signed int value

    // Simulate large number of migrations
    for (int i = 0; i < 1000000; i++) {
        migrateDatabase(currentVersion, targetVersion);
        currentVersion++;
        if (currentVersion >= targetVersion) {
            currentVersion = 1;
        }
    }

    return 0;
}
