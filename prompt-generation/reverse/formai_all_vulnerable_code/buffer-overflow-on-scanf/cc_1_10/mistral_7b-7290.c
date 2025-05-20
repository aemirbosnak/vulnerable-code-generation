//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SBOX_SIZE 4
#define KEY_SIZE 1

// Custom S-Box
unsigned char sbox[SBOX_SIZE][SBOX_SIZE] = {
    {0x67, 0x2B, 0xEF, 0xDC},
    {0xED, 0x86, 0x98, 0x81},
    {0xB3, 0x5D, 0x09, 0x11},
    {0x76, 0x4E, 0xD2, 0x35}
};

// Encrypt function using XOR with S-Box
void encrypt(unsigned char *plaintext, unsigned char key) {
    unsigned char i, j;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = sbox[(plaintext[i] / 0x10) % SBOX_SIZE]
                        [(plaintext[i] % 0x10) ^ key] ^ plaintext[i];
    }
}

// Decrypt function using XOR with S-Box and key
void decrypt(unsigned char *ciphertext, unsigned char key) {
    unsigned char i;
    for (i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] = sbox[(ciphertext[i] / 0x10) % SBOX_SIZE]
                          [(ciphertext[i] % 0x10) ^ key] ^ ~key;
    }
}

int main() {
    unsigned char plaintext[100], ciphertext[100], key;
    printf("Enter a message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    printf("Enter the encryption key (byte): ");
    scanf("%hhu", &key);

    encrypt(plaintext, key);

    printf("Encrypted message: ");
    puts(plaintext);

    printf("\nEnter the encrypted message to decrypt: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strlen(ciphertext) - 1] = '\0';

    decrypt(ciphertext, key);

    printf("Decrypted message: ");
    puts(plaintext);

    return 0;
}