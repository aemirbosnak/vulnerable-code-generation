//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message using Caesar cipher
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (char) (((int) message[i] - 65 + key) % 26) + 65;
            }
            else {
                message[i] = (char) (((int) message[i] - 97 + key) % 26) + 97;
            }
        }
        i++;
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (char) (((int) message[i] - 65 - key + 26) % 26) + 65;
            }
            else {
                message[i] = (char) (((int) message[i] - 97 - key + 26) % 26) + 97;
            }
        }
        i++;
    }
}

// Function to generate a random key
int generateKey() {
    return rand() % 26;
}

int main() {
    char message[100];
    int key;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate random key
    key = generateKey();

    // Encrypt message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}