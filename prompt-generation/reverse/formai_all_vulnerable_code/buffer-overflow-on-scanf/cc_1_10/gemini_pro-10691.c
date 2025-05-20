//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom encryption function
char *encrypt(char *plaintext, int key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + key;
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Custom decryption function
char *decrypt(char *ciphertext, int key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Get the encryption key from the user
    int key;
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the plaintext using the custom function
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the custom function
    char *decrypted_plaintext = decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}