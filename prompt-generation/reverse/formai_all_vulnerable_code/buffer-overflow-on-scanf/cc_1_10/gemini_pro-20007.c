//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 0x12345678

// Encrypt a single byte
unsigned char encryptByte(unsigned char byte) {
    return byte ^ KEY;
}

// Encrypt a string
void encryptString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = encryptByte(str[i]);
    }
}

// Decrypt a single byte
unsigned char decryptByte(unsigned char byte) {
    return byte ^ KEY;
}

// Decrypt a string
void decryptString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = decryptByte(str[i]);
    }
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    encryptString(plaintext);

    // Print the ciphertext
    printf("The ciphertext is: %s\n", plaintext);

    // Decrypt the ciphertext
    decryptString(plaintext);

    // Print the plaintext
    printf("The plaintext is: %s\n", plaintext);

    return 0;
}