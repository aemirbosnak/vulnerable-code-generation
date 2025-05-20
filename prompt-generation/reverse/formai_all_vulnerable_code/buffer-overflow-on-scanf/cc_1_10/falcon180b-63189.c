//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int length = strlen(message);
    char encrypted_message[length + 1]; // Add 1 for null character
    int i = 0, j = 0;

    // Loop through the message
    while (message[i]) {
        // Convert to uppercase
        message[i] = toupper(message[i]);

        // Encrypt using the key
        encrypted_message[j] = message[i] + key;

        // Increment pointers
        i++;
        j++;
    }

    // Add null character to the end of the encrypted message
    encrypted_message[j] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int length = strlen(message);
    char decrypted_message[length + 1]; // Add 1 for null character
    int i = 0, j = 0;

    // Loop through the message
    while (message[i]) {
        // Convert to uppercase
        message[i] = toupper(message[i]);

        // Decrypt using the key
        decrypted_message[j] = message[i] - key;

        // Increment pointers
        i++;
        j++;
    }

    // Add null character to the end of the decrypted message
    decrypted_message[j] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    int key;

    // Get message from user
    printf("Enter the message: ");
    scanf("%s", message);

    // Get key from user
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}