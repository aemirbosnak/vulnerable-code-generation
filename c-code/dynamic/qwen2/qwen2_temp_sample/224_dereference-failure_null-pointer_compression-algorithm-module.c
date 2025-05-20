#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size / 2); // Simulate compression reducing data size by half

    if (compressed == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < size / 2; i++) {
        compressed[i] = data[i]; // Null pointer dereference vulnerability here
    }

    free(compressed);
}

int main() {
    char original[] = "This is a test string to simulate compression";
    int size = sizeof(original);

    printf("Original Data: %s\n", original);

    compress_data(original, size);

    printf("Compressed Data: %s\n", original); // Output will be corrupted due to null pointer dereference

    return 0;
}
