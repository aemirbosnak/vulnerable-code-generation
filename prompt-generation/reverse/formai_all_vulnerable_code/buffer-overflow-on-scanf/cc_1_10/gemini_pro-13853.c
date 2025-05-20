//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret encryption key (modify this to your liking)
#define KEY 7

// Encryption function - transform secret messages into ciphertext
char *encrypt(char *plaintext) {
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY;
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Decryption function - restore secrets from ciphertext
char *decrypt(char *ciphertext) {
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY;
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    // Get the secret message you want to encrypt
    printf("Whisper your secret message (keep it short): ");
    char plaintext[100];
    scanf("%s", plaintext);

    // Encrypt the message using our secret key
    char *ciphertext = encrypt(plaintext);

    // Display the encrypted ciphertext
    printf("\nYour ciphertext masterpiece: %s\n", ciphertext);

    // Decrypt the ciphertext to reveal the secret
    char *decryptedText = decrypt(ciphertext);

    // Voila! The secret is out!
    printf("\nYour decrypted secret: %s\n", decryptedText);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedText);

    return 0;
}