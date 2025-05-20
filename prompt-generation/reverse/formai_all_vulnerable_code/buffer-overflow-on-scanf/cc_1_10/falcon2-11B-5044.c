//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Variables
    char message[100];
    char key[100];
    char encrypted[100];
    char decrypted[100];
    char decryptedMessage[100];
    char errorMessage[100];
    int messageLength;
    int keyLength;
    int i;

    // Get user input for message
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    messageLength = strlen(message);

    // Get user input for key
    printf("Enter a key to use for encryption: ");
    scanf("%s", key);
    keyLength = strlen(key);

    // Encrypt message using Caesar cipher
    for (i = 0; i < messageLength; i++) {
        int index = i % keyLength;
        char shift = ((key[index] - 'a') % 26) + 'a';
        encrypted[i] = (message[i] - 'a') + shift;
    }
    encrypted[messageLength] = '\0';

    // Decrypt message using Caesar cipher
    for (i = 0; i < messageLength; i++) {
        int index = i % keyLength;
        char shift = ((key[index] - 'a') % 26) + 'a';
        decrypted[i] = (encrypted[i] - 'a') + shift;
    }
    decrypted[messageLength] = '\0';

    // Decrypt message using Caesar cipher
    for (i = 0; i < messageLength; i++) {
        int index = i % keyLength;
        char shift = ((key[index] - 'a') % 26) + 'a';
        decryptedMessage[i] = (decrypted[i] - 'a') + shift;
    }
    decryptedMessage[messageLength] = '\0';

    // Print results
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}