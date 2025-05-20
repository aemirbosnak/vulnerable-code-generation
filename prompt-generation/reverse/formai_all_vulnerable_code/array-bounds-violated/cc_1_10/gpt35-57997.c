//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to encrypt the given message using the given key */
void encrypt(char message[], char key[]) {
    int i, j;
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    char encryptedMessage[messageLen];
    
    /* Generate random seed based on current time */
    srand(time(0));
    
    /* Generate a random number between 0 and 25 for each character in the key */
    int keyValues[keyLen];
    for (i = 0; i < keyLen; i++) {
        keyValues[i] = rand() % 26;
    }
    
    /* Encrypt each character in the message using corresponding key value */
    for (i = 0, j = 0; i < messageLen; i++, j++) {
        /* Wrap around key values if message is longer than key */
        if (j >= keyLen) {
            j = 0;
        }
        encryptedMessage[i] = ((message[i] - 'a') + keyValues[j]) % 26 + 'a';
    }
    encryptedMessage[messageLen] = '\0';
    
    /* Print the encrypted message and corresponding key values */
    printf("Encrypted message: %s\n", encryptedMessage);
    printf("Key values: ");
    for (i = 0; i < keyLen; i++) {
        printf("%d ", keyValues[i]);
    }
    printf("\n");
}

int main() {
    char message[100];
    char key[50];
    
    /* Get message and key from user */
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // remove newline character
    
    encrypt(message, key);
    
    return 0;
}