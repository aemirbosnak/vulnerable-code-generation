#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(int* data, int size) {
    int* newData = malloc(size * sizeof(int));
    if (newData == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Simulate database migration logic
    for (int i = 0; i <= size; i++) { // Dereference failure here
        newData[i] = data[i];
    }

    free(newData);
}

int main() {
    int originalData[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalData) / sizeof(originalData[0]);

    migrateDatabase(originalData, size);

    return 0;
}
