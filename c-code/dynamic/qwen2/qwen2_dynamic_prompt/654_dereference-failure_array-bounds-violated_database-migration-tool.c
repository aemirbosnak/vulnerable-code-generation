#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase(int* data, int size) {
    int* temp = malloc(size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Intentional out-of-bounds write
    temp[size] = 42; // This will cause an array bounds violation

    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    free(temp);
}

int main() {
    int originalData[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalData) / sizeof(originalData[0]);

    migrateDatabase(originalData, size);

    return 0;
}
