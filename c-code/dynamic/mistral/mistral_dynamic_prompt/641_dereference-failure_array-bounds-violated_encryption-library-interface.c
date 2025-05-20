#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY_SIZE 256
#define PLATINUM_ENCRYPT_IMPLEMENTATION

void platinum_encrypt(char *plaintext, char *ciphertext) {
    strcpy(ciphertext, plaintext);
    for (int i = 0; i < strlen(ciphertext); ++i)
        ciphertext[i] = ciphertext[i] + 2;
}

void platinum_decrypt(char *ciphertext, char *plaintext) {
    strcpy(plaintext, ciphertext);
    for (int i = 0; i < strlen(plaintext); ++i)
        plaintext[i] = plaintext[i] - 2;
}

int main() {
    const char plaintext[] = "This is a secret message";
    const char *key = "XaZ4L3J1";
    char ciphertext[ENCRYPTION_KEY_SIZE];
    char decrypted_message[ENCRYPTION_KEY_SIZE];

    platinum_encrypt(plaintext, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    platinum_decrypt(ciphertext + strlen(ciphertext) - 1, decrypted_message); // Dereference failure intentional
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}
