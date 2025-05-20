//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
char* encrypt(char* message, int key) {
    int messageLen = strlen(message);
    char* encryptedMessage = (char*)malloc(messageLen * sizeof(char));
    for (int i = 0; i < messageLen; i++) {
        char ch = message[i];
        // Encrypt only alphabets
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') + key) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') + key) % 26 + 'A';
        }
        encryptedMessage[i] = ch;
    }
    encryptedMessage[messageLen] = '\0';
    return encryptedMessage;
}

// Decryption function
char* decrypt(char* message, int key) {
    int messageLen = strlen(message);
    char* decryptedMessage = (char*)malloc(messageLen * sizeof(char));
    for (int i = 0; i < messageLen; i++) {
        char ch = message[i];
        // Decrypt only alphabets
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a') - key + 26) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A') - key + 26) % 26 + 'A';
        }
        decryptedMessage[i] = ch;
    }
    decryptedMessage[messageLen] = '\0';
    return decryptedMessage;
}

int main() {
    char message[100], password[50];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter a password: ");
    fgets(password, 50, stdin);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    // Generate the encryption key based on the password
    int passwordLength = strlen(password);
    int encryptionKey = 0;
    for (int i = 0; i < passwordLength; i++) {
        encryptionKey += password[i];
    }
    encryptionKey = encryptionKey % 26;
    
    // Encrypt the message
    char* encryptedMessage = encrypt(message, key + encryptionKey);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char* decryptedMessage = decrypt(encryptedMessage, key + encryptionKey);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Clean up memory
    free(encryptedMessage);
    free(decryptedMessage);
    
    return 0;
}