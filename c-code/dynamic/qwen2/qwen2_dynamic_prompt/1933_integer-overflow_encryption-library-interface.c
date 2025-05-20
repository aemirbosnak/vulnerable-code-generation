#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(int *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 1;
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
