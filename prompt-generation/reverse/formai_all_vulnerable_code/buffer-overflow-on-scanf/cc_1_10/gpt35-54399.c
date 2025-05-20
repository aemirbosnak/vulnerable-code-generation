//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to generate a random key
void generateKey(char *key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[i] = '\0';
}

// function to encrypt plain text using the key
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = (plaintext[i] + key[i]) % 26 + 'a';
    }
    ciphertext[i] = '\0';
}

// function to decrypt the cipher text using the key
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = (ciphertext[i] - key[i] + 26) % 26 + 'a';
    }
    plaintext[i] = '\0';
}

// main function
int main() {
    char plaintext[100], key[100], ciphertext[100], decryptedtext[100];
    int key_length;

    printf("Enter the plain text: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the length of key: ");
    scanf("%d", &key_length);

    generateKey(key, key_length);

    printf("\n");

    printf("Generated key: %s\n\n", key);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    memset(decryptedtext, 0, sizeof(decryptedtext));

    decrypt(ciphertext, key, decryptedtext);

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}