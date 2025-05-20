//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random key
void generateKey(char* key, int keyLength) {
    srand(time(NULL));
    for (int i = 0; i < keyLength; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt a message using the provided key
void encryptMessage(char* message, char* key, char* encryptedMessage) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    for (int i = 0; i < messageLength; i++) {
        char messageChar = message[i];
        if (isalpha(messageChar)) {
            encryptedMessage[i] = (messageChar - 'a' + key[i % keyLength] - 'a') % 26 + 'a';
        }
        else {
            encryptedMessage[i] = messageChar;
        }
    }
}

// Function to decrypt an encrypted message using the provided key
void decryptMessage(char* encryptedMessage, char* key, char* decryptedMessage) {
    int encryptedMessageLength = strlen(encryptedMessage);
    int keyLength = strlen(key);
    for (int i = 0; i < encryptedMessageLength; i++) {
        char encryptedChar = encryptedMessage[i];
        if (isalpha(encryptedChar)) {
            decryptedMessage[i] = (encryptedChar - 'a' - key[i % keyLength] + 'a') % 26 + 'a';
        }
        else {
            decryptedMessage[i] = encryptedChar;
        }
    }
}

int main() {
    // Prompt user for message to encrypt/decrypt
    char message[100];
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    // Prompt user for encryption/decryption key
    char key[100];
    printf("Enter an encryption/decryption key: ");
    scanf("%s", key);

    // Generate a random encryption key
    char randomKey[100];
    generateKey(randomKey, strlen(message));

    // Encrypt the message using the provided key
    char encryptedMessage[100];
    encryptMessage(message, key, encryptedMessage);

    // Decrypt the encrypted message using the provided key
    char decryptedMessage[100];
    decryptMessage(encryptedMessage, key, decryptedMessage);

    // Print the results
    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}