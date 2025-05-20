#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(int *data, int size) {
    if (size <= 1) return;

    int *compressed = (int *)malloc(size * sizeof(int));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    compressed[0] = data[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (data[i] == compressed[count - 1]) {
            // Intentional overflow here
            compressed[count - 1]++;
            if (compressed[count - 1] < data[i]) {
                printf("Integer overflow occurred\n");
                free(compressed);
                exit(1);
            }
        } else {
            compressed[count++] = data[i];
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress_data(data, size);

    return 0;
}
