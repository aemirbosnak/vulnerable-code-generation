#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *data, int key) {
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        data[i] = data[i] + key;
    }
}

void decrypt(char *data, int key) {
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        data[i] = data[i] - key;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    int key = 3;

    // Encrypt the plaintext
    char *encrypted = malloc(strlen(plaintext) + 1);
    strcpy(encrypted, plaintext);
    encrypt(encrypted, key);

    printf("Encrypted: %s\n", encrypted);

    // Free the encrypted memory
    free(encrypted);

    // Use-after-free vulnerability
    printf("Decrypted: %s\n", encrypted); // Use after free

    return 0;
}
