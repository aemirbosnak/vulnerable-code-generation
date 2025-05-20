//Falcon-180B DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 100
#define MAX_TEXT_SIZE 1000

// Function to encrypt the given text using the given key
void encrypt(char* text, char* key, char* encrypted_text) {
    int i, j;
    int key_index = 0;

    for (i = 0; i < strlen(text); i++) {
        encrypted_text[i] = text[i] + key[key_index % strlen(key)];
        key_index++;
    }

    encrypted_text[i] = '\0';
}

// Function to decrypt the given encrypted text using the given key
void decrypt(char* encrypted_text, char* key, char* decrypted_text) {
    int i, j;
    int key_index = 0;

    for (i = 0; i < strlen(encrypted_text); i++) {
        decrypted_text[i] = encrypted_text[i] - key[key_index % strlen(key)];
        key_index++;
    }

    decrypted_text[i] = '\0';
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_text[MAX_TEXT_SIZE];
    char decrypted_text[MAX_TEXT_SIZE];

    // Get the text to encrypt
    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    // Get the key to use for encryption
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the text using the key
    encrypt(text, key, encrypted_text);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted_text);

    // Decrypt the encrypted text using the same key
    decrypt(encrypted_text, key, decrypted_text);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}