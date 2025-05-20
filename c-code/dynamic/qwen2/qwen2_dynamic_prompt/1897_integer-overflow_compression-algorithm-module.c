#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(int *data, int size) {
    int compressed_size = size * 2;
    int *compressed_data = (int *)malloc(compressed_size * sizeof(int));
    
    if (compressed_data == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        compressed_data[i] = data[i];
        // Integer overflow vulnerability here
        compressed_data[i + size] = compressed_data[i] + compressed_data[i];
    }

    for (int i = 0; i < compressed_size; i++) {
        printf("%d ", compressed_data[i]);
    }
    printf("\n");

    free(compressed_data);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress_data(data, size);

    return 0;
}
