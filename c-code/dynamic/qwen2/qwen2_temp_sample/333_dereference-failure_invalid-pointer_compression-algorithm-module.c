#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size / 2);
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Simulate compression algorithm
    compressed[0] = data[0];
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (data[i] == data[i - 1]) {
            count++;
        } else {
            compressed[count % 2] += '0' + count;
            count = 1;
            compressed[(count + 1) % 2] = data[i];
        }
    }
    compressed[count % 2] += '0' + count;
    
    // This will cause a dereference failure due to invalid pointer
    free(compressed);
    *(compressed + 1) = 'a';  // Dereference after freeing
    
    printf("Compressed data: %s\n", compressed);  // Use of freed memory
}

int main() {
    char *data = "aaaaabbbcc";
    int size = 10;
    compress_data(data, size);
    return 0;
}
