//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt the given string using Caesar cipher
void encrypt(char *message, int key) {
    int i = 0;
    while (message[i]) {
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

// Function to decrypt the given string using Caesar cipher
void decrypt(char *message, int key) {
    int i = 0;
    while (message[i]) {
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

// Function to generate a random key
void generate_key(char *key, int length) {
    int i = 0;
    while (i < length) {
        key[i] = rand() % 26 + 'A';
        i++;
    }
    key[length] = '\0';
}

int main() {
    char message[100], key[100];
    int length, key_length;
    printf("Enter the length of the message: ");
    scanf("%d", &length);
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, length);
    printf("The key is: %s\n", key);

    // Encrypt the message
    encrypt(message, key_length);
    printf("The encrypted message is: %s\n", message);

    // Decrypt the encrypted message
    decrypt(message, key_length);
    printf("The decrypted message is: %s\n", message);

    return 0;
}