#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption library function with intentional buffer overflow
void encrypt(char* input, char* output, int length) {
    char key[] = "SECRET_KEY_12345";
    char ciphertext[20];

    // Insufficient buffer size for long inputs
    for (int i = 0; i < length; i++) {
        char encryptedChar = input[i] ^ key[(i % 5)];
        ciphertext[i] = encryptedChar;
    }
    ciphertext[length] = '\0'; // Set the null terminator
}

int main() {
    char plaintext[10] = "HACKING_IS_FUN";
    char ciphertext[50]; // Incorrect buffer size for the encrypted string

    encrypt(plaintext, ciphertext, strlen(plaintext));

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
