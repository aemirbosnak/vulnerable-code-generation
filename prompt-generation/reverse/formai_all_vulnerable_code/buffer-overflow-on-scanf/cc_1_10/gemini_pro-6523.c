//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32

// Encryption function
char *encrypt(char *plaintext, char *key) {
    int key_len = strlen(key);
    char *ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Decryption function
char *decrypt(char *ciphertext, char *key) {
    int key_len = strlen(key);
    char *plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Get the plaintext and key from the user
    char plaintext[100];
    char key[MAX_KEY_LEN];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the encryption key (max %d characters): ", MAX_KEY_LEN);
    scanf("%s", key);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}