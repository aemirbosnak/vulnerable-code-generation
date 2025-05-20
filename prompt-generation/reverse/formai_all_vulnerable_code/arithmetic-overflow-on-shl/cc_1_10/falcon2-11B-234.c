//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void happyHash(const char *data, int length, unsigned char *result) {
    unsigned int i, j, k;
    int *indexArray;
    int *dataArray;
    int *shiftArray;
    int *xorArray;
    int *hash;

    indexArray = (int*) malloc(length * sizeof(int));
    dataArray = (int*) malloc(length * sizeof(int));
    shiftArray = (int*) malloc(length * sizeof(int));
    xorArray = (int*) malloc(length * sizeof(int));
    hash = (int*) malloc(sizeof(int));

    for (i = 0; i < length; i++) {
        indexArray[i] = i;
        dataArray[i] = data[i];
        shiftArray[i] = 0;
        xorArray[i] = 0;
    }

    for (i = 0; i < length; i++) {
        j = indexArray[i];
        k = (dataArray[j] << shiftArray[i]) ^ xorArray[i];
        hash[i] = k;
        xorArray[i] = k + 1;
    }

    for (i = length - 1; i >= 0; i--) {
        j = indexArray[i];
        k = (dataArray[j] << shiftArray[i]) ^ xorArray[i];
        hash[i] = k;
        xorArray[i] = k + 1;
    }

    for (i = 0; i < length; i++) {
        result[i] = hash[i] % 256;
    }

    free(indexArray);
    free(dataArray);
    free(shiftArray);
    free(xorArray);
    free(hash);
}

int main() {
    const char data[] = "Hello, World!";
    unsigned char result[sizeof(data)];
    int length = strlen(data);

    happyHash(data, length, result);

    printf("Result: ");
    for (int i = 0; i < length; i++) {
        printf("%c", result[i]);
    }
    printf("\n");

    return 0;
}