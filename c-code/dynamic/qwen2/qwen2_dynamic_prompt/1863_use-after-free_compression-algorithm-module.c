#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *data, int size) {
    char *compressed = (char *)malloc(size);
    if (!compressed) return;
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }
    free(compressed);
}

int main() {
    char *data = "This is a test string";
    int size = 21;

    compress(data, size);

    printf("%s\n", data); // Use-after-free vulnerability

    return 0;
}
