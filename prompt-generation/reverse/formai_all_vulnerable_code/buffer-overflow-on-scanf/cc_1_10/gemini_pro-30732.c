//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our happy encryption function!
char* encrypt(char* message, int key) {
    int length = strlen(message);
    char* encryptedMessage = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        encryptedMessage[i] = message[i] + key;
    }
    encryptedMessage[length] = '\0';
    return encryptedMessage;
}

// Our happy decryption function!
char* decrypt(char* message, int key) {
    int length = strlen(message);
    char* decryptedMessage = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        decryptedMessage[i] = message[i] - key;
    }
    decryptedMessage[length] = '\0';
    return decryptedMessage;
}

int main() {
    // Let's get a message from the user!
    printf("Enter your secret message: ");
    char* message = malloc(100);
    scanf("%s", message);

    // Now let's get a key from the user!
    int key;
    printf("Enter your secret key (0-25): ");
    scanf("%d", &key);

    // Time to encrypt the message!
    char* encryptedMessage = encrypt(message, key);

    // Let's show the user the encrypted message!
    printf("Encrypted message: %s\n", encryptedMessage);

    // Now let's decrypt the message!
    char* decryptedMessage = decrypt(encryptedMessage, key);

    // Let's show the user the decrypted message!
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free up the memory we allocated!
    free(message);
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}