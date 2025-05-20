#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        compressed[j++] = data[i];
        // Intentional out-of-bounds write vulnerability
        compressed[j] = data[i]; // This line is intentionally wrong
    }

    free(compressed);
}

int main() {
    char data[] = "This is a test string";
    int size = sizeof(data);

    compress(data, size);

    return 0;
}
