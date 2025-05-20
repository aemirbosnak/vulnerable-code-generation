#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Dereference an invalid pointer to cause a crash
    char *invalid_ptr = NULL;
    printf("Invalid pointer value: %p\n", (void *)invalid_ptr);
    printf("Dereferencing invalid pointer: %c\n", *invalid_ptr); // This will crash

    free(compressed);
}

int main() {
    char data[] = "This is a test string that will cause a crash.";
    int size = sizeof(data);

    compress_data(data, size);

    return 0;
}
