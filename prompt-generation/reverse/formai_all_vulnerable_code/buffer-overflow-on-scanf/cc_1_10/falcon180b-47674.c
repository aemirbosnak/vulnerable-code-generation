//Falcon-180B DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1024

// Function to encrypt the given text using the given key
void encrypt(char* text, char* key) {
    int i, j;
    for (i = 0, j = 0; text[i]!= '\0'; i++, j++) {
        if (j >= strlen(key)) {
            j = 0;
        }
        char cipher_text = text[i] ^ key[j];
        printf("%c", cipher_text);
    }
}

// Function to decrypt the given text using the given key
void decrypt(char* text, char* key) {
    int i, j;
    for (i = 0, j = 0; text[i]!= '\0'; i++, j++) {
        if (j >= strlen(key)) {
            j = 0;
        }
        char plain_text = text[i] ^ key[j];
        printf("%c", plain_text);
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the text to be encrypted/decrypted from user
    printf("Enter the text to be encrypted/decrypted: ");
    scanf("%s", text);

    // Get the key from user
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Encrypt the text using the key
    printf("\nEncrypted text: ");
    encrypt(text, key);
    printf("\n");

    // Decrypt the encrypted text back to original text
    printf("Decrypted text: ");
    decrypt(text, key);
    printf("\n");

    return 0;
}