#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct CompressionData {
    unsigned char* inputBuffer;
    unsigned int inputSize;
    unsigned char* compressedBuffer;
    unsigned int compressedSize;
} CompressionData;

void compressData(CompressionData* data) {
    unsigned int i, j, count = 0;
    for (i = 0; i < data->inputSize; ++i) {
        if (data->inputBuffer[i] == data->inputBuffer[i + 1]) {
            ++count;
        } else {
            data->compressedBuffer[data->compressedSize++] = data->inputBuffer[i];
            if (count > 1) {
                data->compressedBuffer[data->compressedSize++] = count + '0';
                count = 1;
            }
        }
    }
}

int main() {
    CompressionData data;
    data.inputBuffer = (unsigned char[]) { 'a', 'a', 'b', 'a', 'a', 'b', 'c', 'a', 'a', 'd' };
    data.inputSize = 10;

    data.compressedBuffer = (unsigned char[]) { 0 };

    compressData(&data);

    printf("Compressed data: ");
    for (unsigned int i = 0; i < data.compressedSize; ++i) {
        printf("%c", data.compressedBuffer[i]);
    }

    // Dereference a null pointer intentionally, demonstrating a security vulnerability
    printf("\nUnsafe memory access: %c\n", data.inputBuffer[data.inputSize + 10]);

    return 0;
}
