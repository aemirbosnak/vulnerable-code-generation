//FormAI DATASET v1.0 Category: modern Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>

// Declare the encryption key
char key[] = "peaceful";

// Declare the encryption function
char* encrypt(char* message) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int i, j;

    // Allocate memory for the encrypted message
    char* encryptedMessage = (char*) malloc(messageLength+1);

    // Loop through the message and encrypt it
    for (i=0, j=0; i<messageLength; i++,j++) {
        if (j == keyLength) {
            j = 0;
        }
        encryptedMessage[i] = (message[i] + key[j]) % 256;
    }
    encryptedMessage[messageLength] = '\0';

    return encryptedMessage;
}

// Declare the decryption function
char* decrypt(char* message) {
    int keyLength = strlen(key);
    int messageLength = strlen(message);
    int i, j;

    // Allocate memory for the decrypted message
    char* decryptedMessage = (char*) malloc(messageLength+1);

    // Loop through the message and decrypt it
    for (i=0, j=0; i<messageLength; i++,j++) {
        if (j == keyLength) {
            j = 0;
        }
        decryptedMessage[i] = (message[i] - key[j] + 256) % 256;
    }
    decryptedMessage[messageLength] = '\0';

    return decryptedMessage;
}

// Main function
int main() {
    char message[100];

    // Get the message from user input
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]*c", message);

    // Encrypt the message and print it
    char* encryptedMessage = encrypt(message);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message and print it
    char* decryptedMessage = decrypt(encryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}