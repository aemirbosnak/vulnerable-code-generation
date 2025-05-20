//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a unique key for encryption and decryption
char * generateKey(char *message, char *key) {
    int msgLen = strlen(message), keyLen = strlen(key), i, j;
    char *newKey = (char *) malloc(sizeof(char) * (msgLen + 1));

    for(i = 0, j = 0; i < msgLen; ++i, ++j) {
        if(j == keyLen) j = 0;
        newKey[i] = key[j]; 
    }
    newKey[i] = '\0';
    return newKey;
}

// Function for encryption
char * encryptMessage(char *message, char *key) {
    char *encryptedMessage = (char *) malloc(sizeof(char) * (strlen(message) + 1));
    char *newKey = generateKey(message, key);
    int i;

    for(i = 0; i < strlen(message); ++i) {
        if(message[i] == ' ') {
            encryptedMessage[i] = ' ';
        } else {
            encryptedMessage[i] = ((message[i] + newKey[i]) % 26) + 'A';
        }
    }
    encryptedMessage[i] = '\0';
    return encryptedMessage;
}

// Function for decryption
char * decryptMessage(char *encryptedMessage, char *key) {
    char *decryptedMessage = (char *) malloc(sizeof(char) * (strlen(encryptedMessage) + 1));
    char *newKey = generateKey(encryptedMessage, key);
    int i;

    for(i = 0; i < strlen(encryptedMessage); ++i) {
        if(encryptedMessage[i] == ' ') {
            decryptedMessage[i] = ' ';
        } else {
            decryptedMessage[i] = (((encryptedMessage[i] - newKey[i]) + 26) % 26) + 'A';
        }
    }
    decryptedMessage[i] = '\0';
    return decryptedMessage;
}

int main() {
    char message[100], key[100], *encryptedMessage, *decryptedMessage;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    scanf("%[^\n]", key);

    // Encrypt the message
    encryptedMessage = encryptMessage(message, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    decryptedMessage = decryptMessage(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}