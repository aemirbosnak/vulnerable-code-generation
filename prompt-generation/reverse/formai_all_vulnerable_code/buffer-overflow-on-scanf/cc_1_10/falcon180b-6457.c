//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NUM_CHARS 100
#define MAX_NUM_KEYS 10

// Function to generate a random string of a given length
void generateRandomString(char* str, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = chars[rand() % strlen(chars)];
    }
    str[length] = '\0';
}

// Function to generate a public and private key pair
void generateKeys(char* publicKey, char* privateKey) {
    generateRandomString(publicKey, MAX_NUM_CHARS);
    generateRandomString(privateKey, MAX_NUM_CHARS);
}

// Function to encrypt a message using the public key
void encryptMessage(char* message, char* publicKey, char* encryptedMessage) {
    int messageLength = strlen(message);
    int publicKeyLength = strlen(publicKey);
    int encryptedMessageLength = messageLength + publicKeyLength;
    strcpy(encryptedMessage, publicKey);
    strcat(encryptedMessage, message);
}

// Function to decrypt a message using the private key
void decryptMessage(char* encryptedMessage, char* privateKey, char* decryptedMessage) {
    int encryptedMessageLength = strlen(encryptedMessage);
    int privateKeyLength = strlen(privateKey);
    int decryptedMessageLength = encryptedMessageLength - privateKeyLength;
    strcpy(decryptedMessage, encryptedMessage + privateKeyLength);
}

// Main function to run the program
int main() {
    char publicKey[MAX_NUM_KEYS];
    char privateKey[MAX_NUM_KEYS];
    char message[MAX_NUM_CHARS];
    char encryptedMessage[MAX_NUM_CHARS];
    char decryptedMessage[MAX_NUM_CHARS];
    int numKeys = 0;
    int choice = 0;
    do {
        printf("Enter your choice:\n1. Generate public and private keys\n2. Encrypt message\n3. Decrypt message\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                generateKeys(publicKey, privateKey);
                printf("Public key: %s\nPrivate key: %s\n", publicKey, privateKey);
                break;
            case 2:
                printf("Enter message to encrypt:\n");
                scanf("%s", message);
                encryptMessage(message, publicKey, encryptedMessage);
                printf("Encrypted message: %s\n", encryptedMessage);
                break;
            case 3:
                printf("Enter encrypted message to decrypt:\n");
                scanf("%s", encryptedMessage);
                decryptMessage(encryptedMessage, privateKey, decryptedMessage);
                printf("Decrypted message: %s\n", decryptedMessage);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}