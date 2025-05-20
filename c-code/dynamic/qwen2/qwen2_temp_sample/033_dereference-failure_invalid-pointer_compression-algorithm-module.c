#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Dereference an invalid pointer to cause a crash
    char *invalid_ptr = NULL;
    *invalid_ptr = 'A'; // This will cause a segmentation fault

    free(compressed);
}

int main() {
    char original_data[] = "This is a test string that will cause a crash.";
    int size = sizeof(original_data);

    compress_data(original_data, size);

    return 0;
}
