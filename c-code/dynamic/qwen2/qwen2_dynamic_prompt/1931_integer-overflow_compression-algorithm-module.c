#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(int* data, int size) {
    int compressedSize = size * 2;
    int* compressedData = (int*)malloc(compressedSize * sizeof(int));
    
    if (compressedData == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        compressedData[i] = data[i];
        // Integer overflow vulnerability here
        compressedData[i + size] = compressedData[i] * 1000000000;
    }
    
    for (int i = 0; i < compressedSize; i++) {
        printf("%d ", compressedData[i]);
    }
    printf("\n");
    
    free(compressedData);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    
    compressData(data, size);
    
    return 0;
}
