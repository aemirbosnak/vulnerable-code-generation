#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption Algorithm (Fake and Dangerous)
void encrypt(char* plaintext, char* ciphertext) {
    int key = 13;
    int len = strlen(plaintext);

    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] + key;
    }
}

// Decryption Algorithm (Fake and Dangerous)
void decrypt(char* ciphertext, char* plaintext) {
    int key = 13;
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] - key;
    }
}

int main() {
    char plaintext[10] = "SecretMessage";
    char ciphertext[10];
    char decrypted[20];

    encrypt(plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    // Exceeding the buffer size for plaintext during decryption
    decrypt(ciphertext, plaintext);

    return 0;
}
