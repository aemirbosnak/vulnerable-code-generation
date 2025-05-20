//FormAI DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* msg, char* key) {
    int msgLen = strlen(msg);
    int keyLen = strlen(key);
    int i, j;
    char newKey[msgLen], encryptedMsg[msgLen];

    // Repeat the key to match the message length
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[msgLen] = '\0';

    // Encrypted message with XOR encryption
    for (i = 0; i < msgLen; ++i) {
        encryptedMsg[i] = msg[i] ^ newKey[i];
    }
    encryptedMsg[msgLen] = '\0';

    printf("\nMessage: %s", msg);
    printf("\nEncrypted Message: %s", encryptedMsg);
}

void decrypt(char* encryptedMsg, char* key) {
    int msgLen = strlen(encryptedMsg);
    int keyLen = strlen(key);
    int i, j;
    char newKey[msgLen], decryptedMsg[msgLen];

    // Repeat the key to match the message length
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen)
            j = 0;
        newKey[i] = key[j];
    }
    newKey[msgLen] = '\0';

    // Decrypted message with XOR encryption
    for (i = 0; i < msgLen; ++i) {
        decryptedMsg[i] = encryptedMsg[i] ^ newKey[i];
    }
    decryptedMsg[msgLen] = '\0';

    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
}

int main() {
    char msg[100], key[100], choice;

    printf("Enter the message to encrypt: ");
    fgets(msg, 100, stdin);

    printf("Enter the key for encryption: ");
    fgets(key, 100, stdin);

    encrypt(msg, key);

    printf("\n------------------------------\n");

    printf("Do you want to decrypt the message? (Y or N): ");
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        decrypt(msg, key);
    }
    return 0;
}