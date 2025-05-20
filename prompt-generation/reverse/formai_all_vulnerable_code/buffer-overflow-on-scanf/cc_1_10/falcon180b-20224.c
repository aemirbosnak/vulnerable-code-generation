//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "AlanTuringIsMyHero" // This will be our encryption key

// Function to encrypt the given message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
        i++;
    }
}

// Function to decrypt the given message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
        i++;
    }
}

int main() {
    char message[1000];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using Caesar cipher with the given key
    encrypt(message, strlen(KEY) % 26);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the encrypted message back to the original message
    decrypt(message, strlen(KEY) % 26);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}