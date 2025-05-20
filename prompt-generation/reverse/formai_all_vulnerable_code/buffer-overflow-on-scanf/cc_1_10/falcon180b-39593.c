//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key) {
    int i, j;
    char ch;
    for (i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z')
                ch = ch - 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z')
                ch = ch - 26;
        }
        message[i] = ch;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key) {
    int i, j;
    char ch;
    for (i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a')
                ch = ch + 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A')
                ch = ch + 26;
        }
        message[i] = ch;
    }
}

// Function to generate a random key
int generateKey() {
    int key;
    key = rand() % 26;
    return key;
}

int main() {
    char message[100];
    int key;

    // Get the message from user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    key = generateKey();

    // Encrypt the message
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}