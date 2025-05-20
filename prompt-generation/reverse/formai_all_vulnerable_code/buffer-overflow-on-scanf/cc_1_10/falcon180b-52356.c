//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char *message, char *key) {
    int i, j, k;
    char temp;

    // Length of the message
    int message_length = strlen(message);

    // Length of the key
    int key_length = strlen(key);

    // Loop through the message
    for (i = 0; i < message_length; i++) {

        // Convert the message to uppercase
        message[i] = toupper(message[i]);

        // Encrypt the message using the key
        if (isalpha(message[i])) {
            if (isalpha(key[i % key_length])) {
                temp = message[i] + key[i % key_length] - 'A';
                if (temp > 'Z') {
                    temp = temp - 26;
                }
                message[i] = temp;
            }
            else {
                message[i] = message[i] + key[i % key_length];
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, char *key) {
    int i, j, k;
    char temp;

    // Length of the message
    int message_length = strlen(message);

    // Length of the key
    int key_length = strlen(key);

    // Loop through the message
    for (i = 0; i < message_length; i++) {

        // Convert the message to uppercase
        message[i] = toupper(message[i]);

        // Decrypt the message using the key
        if (isalpha(message[i])) {
            if (isalpha(key[i % key_length])) {
                temp = message[i] - key[i % key_length] - 'A';
                if (temp < 0) {
                    temp = temp + 26;
                }
                message[i] = temp;
            }
            else {
                message[i] = message[i] - key[i % key_length];
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

int main() {
    char message[100], key[100];

    // Get the message and key from the user
    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("\nEncrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("\nDecrypted message: %s\n", message);

    return 0;
}