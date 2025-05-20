#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(int *data, int length) {
    int key = 12345;
    for (int i = 0; i < length; i++) {
        data[i] += key; // Integer overflow vulnerability
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);

    printf("Original data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    encrypt(data, length);

    printf("Encrypted data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
