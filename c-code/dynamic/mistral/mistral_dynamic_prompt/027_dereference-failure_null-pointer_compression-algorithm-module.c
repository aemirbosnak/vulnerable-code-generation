#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compressData(char* data) {
    char* compressedData = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int index = 0;
    char currentChar;

    while ((currentChar = data[index++])) {
        if (index >= BUFFER_SIZE) {
            printf("Buffer overflow!\n");
            break;
        }

        if (compressedData[index - 1] == currentChar) {
            compressedData[index - 1]++;
        } else {
            compressedData[index] = currentChar;
        }
    }

    compressedData[index] = '\0';
}

void decompressData(char* compressedData) {
    char* decompressedData = (char*) malloc(BUFFER_SIZE * sizeof(char));
    int index = 0, counter = 0;

    while (compressedData[index]) {
        if (compressedData[index] <= counter) {
            index++;
            counter = compressedData[index];
        } else {
            decompressedData[counter] = compressedData[index];
            counter++;
            index++;
        }
    }

    decompressedData[counter] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <data to compress>\n", argv[0]);
        return 1;
    }

    char* inputData = argv[1];
    char* compressedData;
    compressData(inputData);
    printf("Compressed data: %s\n", compressedData);

    char* decompressedData;
    decompressData(compressedData);
    printf("Decompressed data: %s\n", decompressedData);

    free(compressedData);
    free(decompressedData);
    free(inputData);

    return 0;
}
