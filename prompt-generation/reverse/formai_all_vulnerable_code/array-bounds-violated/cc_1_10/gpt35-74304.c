//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform Modern Encryption */
char* modernEncrypt(char* message, char* key) {
    char* encryptedMessage = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    int i, j, k, n;

    /* Generating the keystream based on the key */
    char keystream[strlen(message)];
    for(i = 0, j = 0; i < strlen(message); i++, j++) {
        if(j == strlen(key))
            j = 0;
        keystream[i] = key[j];
    }

    /* XORing each character of message with each character of keystream */
    for(i = 0; i < strlen(message); i++) {
        encryptedMessage[i] = message[i] ^ keystream[i];
    }
    encryptedMessage[strlen(message)] = '\0';

    return encryptedMessage;
}

int main() {
    char message[100], key[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);

    /* Removing the newline character from the end of the strings */
    message[strlen(message) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    /* Printing the original message and key */
    printf("Original Message: %s\n", message);
    printf("Original Key: %s\n\n", key);

    /* Performing encryption */
    char* encryptedMessage = modernEncrypt(message, key);

    /* Printing the encrypted message */
    printf("Encrypted Message: %s\n\n", encryptedMessage);

    /* Freeing the dynamically allocated memory */
    free(encryptedMessage);

    return 0;
}