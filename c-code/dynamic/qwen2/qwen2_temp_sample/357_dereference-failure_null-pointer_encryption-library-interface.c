#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt_data(int* data, int length, int key) {
    if (data == NULL) {
        printf("Error: Null pointer passed to encrypt_data\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        data[i] += key;
    }
}

void decrypt_data(int* data, int length, int key) {
    if (data == NULL) {
        printf("Error: Null pointer passed to decrypt_data\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        data[i] -= key;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int key = 7;

    printf("Original Data:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    encrypt_data(data, length, key);
    printf("Encrypted Data:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    decrypt_data(data, length, key);
    printf("Decrypted Data:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Deliberate null pointer dereference
    int *null_ptr = NULL;
    *null_ptr = 10; // This will cause a segmentation fault

    return 0;
}
