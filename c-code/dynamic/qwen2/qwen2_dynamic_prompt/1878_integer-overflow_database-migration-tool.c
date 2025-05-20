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
    for (int i = 0; i < 10; i++) {
        data[i] = i * 10;
    }

    int targetSize = oldVersion + newVersion;

    // Integer overflow vulnerability here
    int newSize = targetSize * 2;

    if (newSize < targetSize) {
        printf("Integer overflow detected!\n");
        exit(1);
    }

    int newData[newSize];

    for (int i = 0; i < targetSize; i++) {
        newData[i] = data[i];
    }

    for (int i = targetSize; i < newSize; i++) {
        newData[i] = i - targetSize;
    }

    printf("Migration successful! New size: %d\n", newSize);

    for (int i = 0; i < newSize; i++) {
        printf("%d ", newData[i]);
    }
    printf("\n");
}

int main() {
    int oldVersion = 1000000000;
    int newVersion = 1;

    migrateDatabase(oldVersion, newVersion);

    return 0;
}
