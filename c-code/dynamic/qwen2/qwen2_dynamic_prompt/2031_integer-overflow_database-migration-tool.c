#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(int currentVersion, int targetVersion) {
    if (currentVersion > targetVersion) {
        printf("Downgrading from version %d to %d\n", currentVersion, targetVersion);
    } else {
        printf("Upgrading from version %d to %d\n", currentVersion, targetVersion);
    }
}

int main() {
    int currentVersion = 1;
    int targetVersion = 2147483647; // Maximum signed int value

    // Simulate a large number of migrations
    for (int i = 0; i < 1000000; i++) {
        migrateDatabase(currentVersion, targetVersion);
        currentVersion++;
        targetVersion--;
    }

    return 0;
}
