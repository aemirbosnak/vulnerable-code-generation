//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "MySecretKey"

// Function to encrypt the message
void encrypt(char *message) {
    int length = strlen(message);
    char encrypted_message[length];
    int i;

    // Loop through each character in the message
    for (i = 0; i < length; i++) {
        // Get the ASCII value of the character
        char c = message[i];
        int ascii_value = (int) c;

        // Encrypt the character using the key
        ascii_value += (int) ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];

        // Convert the encrypted ASCII value to a character
        encrypted_message[i] = (char) ascii_value;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char *message) {
    int length = strlen(message);
    char decrypted_message[length];
    int i;

    // Loop through each character in the message
    for (i = 0; i < length; i++) {
        // Get the ASCII value of the character
        char c = message[i];
        int ascii_value = (int) c;

        // Decrypt the character using the key
        ascii_value -= (int) ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];

        // Convert the decrypted ASCII value to a character
        decrypted_message[i] = (char) ascii_value;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Decrypt the encrypted message
    decrypt(message);

    return 0;
}