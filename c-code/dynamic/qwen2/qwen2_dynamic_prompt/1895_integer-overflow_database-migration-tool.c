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

    int data[10];
    for (int i = 0; i <= oldVersion; i++) {
        data[i] = i * 10;
    }

    int targetSize = oldVersion + newVersion;
    int* newData = malloc(targetSize * sizeof(int));
    if (newData == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i <= oldVersion; i++) {
        newData[i] = data[i];
    }

    // Integer overflow vulnerability
    int overflowIndex = targetSize - 1;
    newData[overflowIndex] += 1;

    for (int i = 0; i <= targetSize; i++) {
        printf("newData[%d] = %d\n", i, newData[i]);
    }

    free(newData);
}

int main() {
    int oldVersion = 9;
    int newVersion = 2147483647; // Maximum positive int value

    migrateDatabase(oldVersion, newVersion);

    return 0;
}
