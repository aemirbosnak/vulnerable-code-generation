#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void migrate_data(int *data, int size) {
    int new_buffer[BUFFER_SIZE];
    for (int i = 0; i <= size; i++) { // Dereference failure here: out-of-bounds access
        new_buffer[i] = data[i];
    }
}

int main() {
    int original_data[] = {1, 2, 3, 4, 5};
    int size = sizeof(original_data) / sizeof(original_data[0]);

    migrate_data(original_data, size);

    printf("Migration successful.\n");

    return 0;
}
