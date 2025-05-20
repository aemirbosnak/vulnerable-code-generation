//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_IV_SIZE 16

// Function to generate a random key and initialization vector
void generate_key_and_iv(char* key, char* iv) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';

    for (int i = 0; i < MAX_IV_SIZE; i++) {
        iv[i] = rand() % 26 + 'a';
    }
    iv[MAX_IV_SIZE] = '\0';
}

// Function to encrypt the plaintext using the key and initialization vector
void encrypt(char* plaintext, char* key, char* iv, char* ciphertext) {
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + MAX_IV_SIZE;

    // Encrypt the plaintext using the key and initialization vector
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % MAX_KEY_SIZE];
    }

    // Append the initialization vector to the ciphertext
    for (int i = 0; i < MAX_IV_SIZE; i++) {
        ciphertext[plaintext_len + i] = iv[i];
    }
}

// Function to decrypt the ciphertext using the key and initialization vector
void decrypt(char* ciphertext, char* key, char* iv, char* plaintext) {
    int plaintext_len = strlen(ciphertext) - MAX_IV_SIZE;

    // Decrypt the ciphertext using the key and initialization vector
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % MAX_KEY_SIZE];
    }
}

int main() {
    char key[MAX_KEY_SIZE + 1];
    char iv[MAX_IV_SIZE + 1];
    char plaintext[1000];
    char ciphertext[1000];

    // Generate a random key and initialization vector
    generate_key_and_iv(key, iv);

    // Encrypt the plaintext
    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);
    encrypt(plaintext, key, iv, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, iv, plaintext);

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}