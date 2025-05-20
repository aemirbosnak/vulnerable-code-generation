//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom key generator function
unsigned long long generate_key(const char *password) {
    unsigned long long key = 0;
    for (int i = 0; i < strlen(password); i++) {
        key = key * 31 + password[i];
    }
    return key;
}

// Encryption function using XOR
char *encrypt(const char *plaintext, unsigned long long key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ (key >> (i % 8));
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Decryption function using XOR
char *decrypt(const char *ciphertext, unsigned long long key) {
    char *plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ (key >> (i % 8));
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main() {
    // Prompt the user for a password and plaintext
    char password[1024];
    printf("Enter a password: ");
    scanf("%s", password);
    char plaintext[1024];
    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);

    // Generate the encryption key from the password
    unsigned long long key = generate_key(password);

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the key
    char *plaintext_decrypted = decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext_decrypted);

    return 0;
}