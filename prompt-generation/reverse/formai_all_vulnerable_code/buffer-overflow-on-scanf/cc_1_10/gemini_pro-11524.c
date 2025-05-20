//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: excited
// Enigma Encrypter: Unleash the Cryptographic Storm!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic Memory Allocation for Encrypted Messages
char *encrypt(char *message, int key) {
    // Calculate Encrypted Message Length
    int encryptedLength = strlen(message) + 1;

    // Allocate Memory for Encrypted Message
    char *encryptedMessage = malloc(encryptedLength * sizeof(char));

    // Encrypt Character by Character
    for (int i = 0; i < strlen(message); i++) {
        encryptedMessage[i] = message[i] + key;
    }

    // Terminate Encrypted Message
    encryptedMessage[strlen(message)] = '\0';

    // Return Encrypted Message
    return encryptedMessage;
}

// Back to Plaintext: Decryption Unveils the Secrets
char *decrypt(char *encryptedMessage, int key) {
    // Calculate Decrypted Message Length
    int decryptedLength = strlen(encryptedMessage) + 1;

    // Allocate Memory for Decrypted Message
    char *decryptedMessage = malloc(decryptedLength * sizeof(char));

    // Decrypt Character by Character
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        decryptedMessage[i] = encryptedMessage[i] - key;
    }

    // Terminate Decrypted Message
    decryptedMessage[strlen(encryptedMessage)] = '\0';

    // Return Decrypted Message
    return decryptedMessage;
}

int main(void) {
    // Prepare to Encrypt: Message and Key Input
    char message[100];
    int key;
    printf("Enter your secret message to encrypt: ");
    scanf("%s", message);
    printf("Choose your encryption key: ");
    scanf("%d", &key);

    // Encryption: Transforming Secrets into Enigmatic Code
    char *encryptedMessage = encrypt(message, key);
    printf("Behold! Your encrypted message: %s\n", encryptedMessage);

    // Decryption: Unraveling the Enigmatic Code
    char *decryptedMessage = decrypt(encryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Mission Accomplished: Encryption and Decryption Triumph
    printf("Encryption and decryption mission accomplished! Your secrets are safe with us.\n");

    // Free Allocated Memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}