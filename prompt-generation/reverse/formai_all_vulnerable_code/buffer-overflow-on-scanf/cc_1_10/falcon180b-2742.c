//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the given message using a key
void encrypt(char *message, char *key) {
    int length = strlen(message);
    int keylen = strlen(key);
    int i = 0, j = 0;

    // Loop through the message and key
    while (i < length) {
        // If the key is exhausted, start over
        if (j >= keylen) {
            j = 0;
        }

        // Encrypt the character using the key
        char encrypted_char = (char) ((message[i] + key[j]) % 26 + 'A');

        // Add the encrypted character to the result
        printf("%c", encrypted_char);

        // Move to the next character in the key
        j++;

        // Move to the next character in the message
        i++;
    }
}

// Function to decrypt the given message using a key
void decrypt(char *message, char *key) {
    int length = strlen(message);
    int keylen = strlen(key);
    int i = 0, j = 0;

    // Loop through the message and key
    while (i < length) {
        // If the key is exhausted, start over
        if (j >= keylen) {
            j = 0;
        }

        // Decrypt the character using the key
        char decrypted_char = (char) ((message[i] - key[j] + 26) % 26 + 'A');

        // Add the decrypted character to the result
        printf("%c", decrypted_char);

        // Move to the next character in the key
        j++;

        // Move to the next character in the message
        i++;
    }
}

// Main function
int main() {
    // Get the message and key from the user
    char message[100];
    char key[100];
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message using the key
    printf("\nEncrypted message: ");
    encrypt(message, key);
    printf("\n");

    // Decrypt the encrypted message using the key
    printf("Decrypted message: ");
    decrypt(message, key);
    printf("\n");

    return 0;
}