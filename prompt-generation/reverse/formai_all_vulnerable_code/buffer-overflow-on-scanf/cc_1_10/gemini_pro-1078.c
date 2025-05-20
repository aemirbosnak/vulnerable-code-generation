//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// XOR encryption function
char* xor_encrypt(char* plaintext, char* key) {
    // Get the lengths of the plaintext and key
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    // Create a buffer to store the ciphertext
    char* ciphertext = malloc(plaintext_len + 1);

    // Loop through the plaintext and XOR each character with the corresponding character in the key
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Terminate the ciphertext with a null character
    ciphertext[plaintext_len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// XOR decryption function
char* xor_decrypt(char* ciphertext, char* key) {
    // Get the lengths of the ciphertext and key
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    // Create a buffer to store the plaintext
    char* plaintext = malloc(ciphertext_len + 1);

    // Loop through the ciphertext and XOR each character with the corresponding character in the key
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Terminate the plaintext with a null character
    plaintext[ciphertext_len] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char* plaintext = malloc(100);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Get the key from the user
    char* key = malloc(100);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the plaintext using the XOR encryption function
    char* ciphertext = xor_encrypt(plaintext, key);

    // Decrypt the ciphertext using the XOR decryption function
    char* decrypted_plaintext = xor_decrypt(ciphertext, key);

    // Print the ciphertext and the decrypted plaintext
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(plaintext);
    free(key);
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}