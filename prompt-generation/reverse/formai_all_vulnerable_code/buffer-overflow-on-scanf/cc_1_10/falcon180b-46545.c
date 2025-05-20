//Falcon-180B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

// Function to encrypt the message using the given key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length + 1];

    // Initialize the encrypted message to empty string
    memset(encrypted_message, 0, message_length + 1);

    // Encrypt the message
    int i = 0, j = 0;
    while (i < message_length) {
        if (isalpha(message[i])) {
            // Shift the character by the key value
            char shifted_char = toupper(message[i]) + key_length - 65;
            if (shifted_char > 90) {
                shifted_char -= 26;
            }
            encrypted_message[j++] = shifted_char;
        }
        else {
            // Copy non-alphabetic characters as is
            encrypted_message[j++] = message[i];
        }
        i++;
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the given key
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[encrypted_message_length + 1];

    // Initialize the decrypted message to empty string
    memset(decrypted_message, 0, encrypted_message_length + 1);

    // Decrypt the message
    int i = 0, j = 0;
    while (i < encrypted_message_length) {
        if (isalpha(encrypted_message[i])) {
            // Shift the character back by the key value
            char shifted_char = encrypted_message[i] - key_length + 65;
            if (shifted_char < 65) {
                shifted_char += 26;
            }
            decrypted_message[j++] = shifted_char;
        }
        else {
            // Copy non-alphabetic characters as is
            decrypted_message[j++] = encrypted_message[i];
        }
        i++;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_KEY_LENGTH + 1];
    char key[MAX_KEY_LENGTH + 1];

    // Get the message from user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the key from user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}