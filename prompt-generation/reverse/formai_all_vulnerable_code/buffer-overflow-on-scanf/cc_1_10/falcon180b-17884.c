//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message using Caesar Cipher
void encrypt(char message[], int key) {
    int i, length = strlen(message);
    for (i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 'A' + key) % 26) + 'A';
            } else {
                message[i] = ((message[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt message using Caesar Cipher
void decrypt(char message[], int key) {
    int i, length = strlen(message);
    for (i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to generate random key between 1 and 25
int generateKey() {
    return rand() % 25 + 1;
}

int main() {
    char message[100], encrypted[100], decrypted[100];
    int key;

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Generate random key
    key = generateKey();

    // Encrypt message
    encrypt(message, key);
    strcpy(encrypted, message);

    // Decrypt message
    decrypt(encrypted, key);
    strcpy(decrypted, encrypted);

    // Print encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}