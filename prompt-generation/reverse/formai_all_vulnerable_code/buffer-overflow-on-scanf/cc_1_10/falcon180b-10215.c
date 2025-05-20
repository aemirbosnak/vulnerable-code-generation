//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 16
#define MAX_PLAIN_TEXT_LEN 1024
#define MAX_CIPHER_TEXT_LEN (MAX_PLAIN_TEXT_LEN + 1)

// Function to encrypt plain text using the Vigenere cipher
void vigenere_encrypt(char* plain_text, char* key, char* cipher_text) {
    int i, j, key_index = 0;
    for (i = 0; plain_text[i]!= '\0'; i++) {
        if (isalpha(plain_text[i])) {
            cipher_text[i] = 'A' + ((int) plain_text[i] - 65 + (int) key[key_index % strlen(key)] - 65) % 26;
            key_index++;
        } else {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[i] = '\0';
}

// Function to decrypt cipher text using the Vigenere cipher
void vigenere_decrypt(char* cipher_text, char* key, char* plain_text) {
    int i, j, key_index = 0;
    for (i = 0; cipher_text[i]!= '\0'; i++) {
        if (isalpha(cipher_text[i])) {
            plain_text[i] = 'A' + ((int) cipher_text[i] - 65 - (int) key[key_index % strlen(key)] - 65 + 26) % 26;
            key_index++;
        } else {
            plain_text[i] = cipher_text[i];
        }
    }
    plain_text[i] = '\0';
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_LEN];
    char key[MAX_KEY_LEN];
    char cipher_text[MAX_CIPHER_TEXT_LEN];

    // Get plain text from user
    printf("Enter plain text to encrypt/decrypt: ");
    scanf("%s", plain_text);

    // Get key from user
    printf("Enter key for Vigenere cipher: ");
    scanf("%s", key);

    // Check if key is valid
    int key_len = strlen(key);
    if (key_len == 0 || key_len > MAX_KEY_LEN) {
        printf("Invalid key!\n");
        return 1;
    }

    // Encrypt plain text using Vigenere cipher
    vigenere_encrypt(plain_text, key, cipher_text);

    // Print encrypted cipher text
    printf("Encrypted text: %s\n", cipher_text);

    // Decrypt cipher text using Vigenere cipher
    vigenere_decrypt(cipher_text, key, plain_text);

    // Print decrypted plain text
    printf("Decrypted text: %s\n", plain_text);

    return 0;
}