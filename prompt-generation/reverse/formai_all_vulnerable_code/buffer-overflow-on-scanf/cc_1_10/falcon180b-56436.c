//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = message[i] + key - 65;
                if (message[i] > 90) {
                    message[i] = message[i] - 26;
                }
            } else {
                message[i] = message[i] + key - 97;
                if (message[i] > 122) {
                    message[i] = message[i] - 26;
                }
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = message[i] - key - 65;
                if (message[i] < 65) {
                    message[i] = message[i] + 26;
                }
            } else {
                message[i] = message[i] - key - 97;
                if (message[i] < 97) {
                    message[i] = message[i] + 26;
                }
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to generate a random key for encryption
int generateKey() {
    int key;
    srand(time(NULL));
    key = rand() % 26;
    return key;
}

int main() {
    char message[MAX_SIZE];
    char encryptedMessage[MAX_SIZE];
    char decryptedMessage[MAX_SIZE];
    int key;

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key for encryption
    key = generateKey();

    // Encrypt the message
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    decrypt(encryptedMessage, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}