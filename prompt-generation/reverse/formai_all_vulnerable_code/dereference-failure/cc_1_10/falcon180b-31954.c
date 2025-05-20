//Falcon-180B DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* Function to encrypt a message using a key */
void encrypt(char *message, int key) {
    int len = strlen(message);
    char *result = malloc(len + 1); // Allocate memory for the result
    int i;

    // Encrypt each character using the key
    for (i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            result[i] = (char) (((message[i] - 'a' + key) % 26) + 'a');
        } else {
            result[i] = message[i];
        }
    }
    result[len] = '\0'; // Add null terminator

    // Print the encrypted message
    printf("Encrypted message: %s\n", result);
}

/* Function to decrypt a message using a key */
void decrypt(char *message, int key) {
    int len = strlen(message);
    char *result = malloc(len + 1); // Allocate memory for the result
    int i;

    // Decrypt each character using the key
    for (i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            result[i] = (char) (((message[i] - 'a' - key) % 26) + 'a');
        } else {
            result[i] = message[i];
        }
    }
    result[len] = '\0'; // Add null terminator

    // Print the decrypted message
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100] = "Hello, World!";
    int key = 5;

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    char encrypted[100] = "Mjqqt, S'vz!";
    decrypt(encrypted, key);

    return 0;
}