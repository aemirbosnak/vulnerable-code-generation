#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateDatabase() {
    int *data = (int *)malloc(10 * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate some database operations
    for (int i = 0; i < 10; i++) {
        data[i] = i + 1;
    }

    // Free the allocated memory
    free(data);

    // Use-after-free vulnerability
    printf("Data[5] = %d\n", data[5]); // Accessing freed memory
}

int main() {
    migrateDatabase();
    return 0;
}
