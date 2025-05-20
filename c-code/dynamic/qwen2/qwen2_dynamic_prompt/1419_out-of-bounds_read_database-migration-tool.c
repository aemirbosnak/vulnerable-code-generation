#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void migrate_data(int *data, int size) {
    int buffer[BUFFER_SIZE];
    for (int i = 0; i <= size; i++) { // Out-of-bounds read
        buffer[i] = data[i];
    }
}

int main() {
    int original_data[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    migrate_data(original_data, 20);
    return 0;
}
