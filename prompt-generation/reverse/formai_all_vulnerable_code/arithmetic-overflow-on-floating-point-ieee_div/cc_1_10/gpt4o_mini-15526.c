//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key for encryption
void generate_key(char *key, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        key[i] = charset[index];
    }
    key[length] = '\0'; // Null-terminate the string
}

// Function to encrypt the plaintext using XOR cipher
void encrypt(const char *plaintext, const char *key, char *ciphertext) {
    size_t text_length = strlen(plaintext);
    for (size_t i = 0; i < text_length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    ciphertext[text_length] = '\0'; // Null-terminate the string
}

// Function to decrypt the ciphertext using XOR cipher
void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    size_t text_length = strlen(ciphertext);
    for (size_t i = 0; i < text_length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }
    plaintext[text_length] = '\0'; // Null-terminate the string
}

void print_statistics(const char *original, const char *ciphered) {
    int original_length = strlen(original);
    int ciphered_length = strlen(ciphered);
  
    printf("\n--- Statistics ---\n");
    printf("Original Length: %d\n", original_length);
    printf("Ciphered Length: %d\n", ciphered_length);
    printf("Compression Ratio: %.2f\n", (float)original_length / ciphered_length);
}

int main() {
    srand(time(0)); // Seed the random number generator
    const int KEY_LENGTH = 16;
    char key[KEY_LENGTH + 1];
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];

    // Generating a random key
    generate_key(key, KEY_LENGTH);
    printf("Random Key: %s\n", key);

    // Taking user input for plaintext
    printf("Enter the plaintext (max 255 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    // Encrypting the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypting the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    // Print statistics
    print_statistics(plaintext, ciphertext);

    return 0;
}