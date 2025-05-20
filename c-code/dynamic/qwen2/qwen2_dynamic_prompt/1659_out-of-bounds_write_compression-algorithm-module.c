#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) return;

    int j = 0;
    for (int i = 0; i < size; i++) {
        compressed[j++] = data[i];
        while (i + 1 < size && data[i] == data[i + 1]) {
            i++;
        }
        compressed[j++] = i - j + '0';
    }

    // Out-of-bounds write
    compressed[size] = 'A'; // This will overwrite memory beyond the allocated space

    free(compressed);
}

int main() {
    char data[] = "aaabbbcc";
    int size = sizeof(data) / sizeof(data[0]);

    compress(data, size);

    printf("Original: %s\n", data);

    return 0;
}
