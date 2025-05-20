//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to encrypt the message
void encrypt(char *message) {
    int i, j, k;
    char key[MAX_LENGTH];
    printf("Enter the key: ");
    scanf("%s", key);

    // Calculate the length of the message
    int length = strlen(message);

    // Initialize the encrypted message
    char encrypted_message[MAX_LENGTH];
    for (i = 0; i < length; i++) {
        // Get the ASCII value of the message character
        int message_char = message[i];

        // Get the ASCII value of the key character
        int key_char = tolower(key[i % strlen(key)]);

        // Encrypt the message character
        encrypted_message[i] = (message_char + key_char) % 26 + 'a';
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char *message) {
    int i, j, k;
    char key[MAX_LENGTH];
    printf("Enter the key: ");
    scanf("%s", key);

    // Calculate the length of the message
    int length = strlen(message);

    // Initialize the decrypted message
    char decrypted_message[MAX_LENGTH];
    for (i = 0; i < length; i++) {
        // Get the ASCII value of the message character
        int message_char = message[i];

        // Get the ASCII value of the key character
        int key_char = tolower(key[i % strlen(key)]);

        // Decrypt the message character
        decrypted_message[i] = (message_char - key_char + 26) % 26 + 'a';
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Main function
int main() {
    char message[MAX_LENGTH];
    printf("Enter the message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    char encrypted_message[MAX_LENGTH];
    strcpy(encrypted_message, message);
    decrypt(encrypted_message);

    return 0;
}