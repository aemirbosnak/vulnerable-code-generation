#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data) {
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        data[i] += 3;
    }
}

void decrypt(char *data) {
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        data[i] -= 3;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    printf("Plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext);
    printf("Encrypted: %s\n", plaintext);

    // Free the memory
    free(plaintext);

    // Use after free vulnerability
    printf("Decrypted: %s\n", plaintext);

    return 0;
}
