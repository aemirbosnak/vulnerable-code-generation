//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a character using a Caesar cipher with a given key
char encrypt_char(char plaintext, int key) {
    return ((plaintext - 'a' + key) % 26) + 'a';
}

// Encrypt a string using a Caesar cipher with a given key
char* encrypt_string(char* plaintext, int key) {
    int len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = encrypt_char(plaintext[i], key);
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Decrypt a character using a Caesar cipher with a given key
char decrypt_char(char ciphertext, int key) {
    return ((ciphertext - 'a' - key + 26) % 26) + 'a';
}

// Decrypt a string using a Caesar cipher with a given key
char* decrypt_string(char* ciphertext, int key) {
    int len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        plaintext[i] = decrypt_char(ciphertext[i], key);
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main() {
    // Initialize the secret key
    int key = 7;

    // Read the plain text message from the user
    char plaintext[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", plaintext);

    // Encrypt the message using the Arcane Codex Protector
    char* ciphertext = encrypt_string(plaintext, key);

    // Display the encrypted ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Arcane Codex Protector
    char* decrypted_text = decrypt_string(ciphertext, key);

    // Display the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_text);

    // Release the memory allocated for the ciphertexts
    free(ciphertext);
    free(decrypted_text);

    return 0;
}