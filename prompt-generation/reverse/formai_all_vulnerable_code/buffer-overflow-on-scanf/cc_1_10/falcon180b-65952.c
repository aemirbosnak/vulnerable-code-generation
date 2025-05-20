//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_PLAIN_TEXT_LENGTH 1000

// Function to encrypt the plain text using the given key
void encrypt(char *plain_text, char *key) {
    int key_length = strlen(key);
    int plain_text_length = strlen(plain_text);
    char *cipher_text = malloc(plain_text_length + 1);
    int j = 0;

    // Loop through each character in the plain text
    for (int i = 0; i < plain_text_length; i++) {
        // Convert the character to uppercase
        plain_text[i] = toupper(plain_text[i]);

        // Encrypt the character using the key
        cipher_text[j++] = 'A' + ((plain_text[i] - 'A' + key_length) % 26);
    }

    // Add a null terminator to the end of the cipher text
    cipher_text[j] = '\0';

    // Print the encrypted text
    printf("Encrypted text: %s\n", cipher_text);
}

// Function to decrypt the cipher text using the given key
void decrypt(char *cipher_text, char *key) {
    int key_length = strlen(key);
    int cipher_text_length = strlen(cipher_text);
    char *plain_text = malloc(cipher_text_length + 1);
    int j = 0;

    // Loop through each character in the cipher text
    for (int i = 0; i < cipher_text_length; i++) {
        // Convert the character to uppercase
        cipher_text[i] = toupper(cipher_text[i]);

        // Decrypt the character using the key
        plain_text[j++] = 'A' + ((cipher_text[i] - 'A' - key_length + 26) % 26);
    }

    // Add a null terminator to the end of the plain text
    plain_text[j] = '\0';

    // Print the decrypted text
    printf("Decrypted text: %s\n", plain_text);
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the plain text and key from the user
    printf("Enter the plain text: ");
    scanf("%s", plain_text);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the plain text using the key
    encrypt(plain_text, key);

    // Decrypt the encrypted text using the key
    decrypt(plain_text, key);

    return 0;
}