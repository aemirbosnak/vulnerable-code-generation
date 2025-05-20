//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

// Function to generate key
void generateKey(char *key) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int keyIndex = 0;
    for (int i = 0; i < KEY_SIZE; i++) {
        while (!isalpha(charset[rand() % strlen(charset)])) { // Ensure key is alphabetic
            rand();
        }
        key[i] = charset[rand() % strlen(charset)];
        keyIndex++;
    }
    printf("Key generated: %s\n", key);
}

// Function to encrypt message
void encrypt(char *message, char *key) {
    int messageIndex = 0;
    int keyIndex = 0;
    while (message[messageIndex]) {
        message[messageIndex] = toupper(message[messageIndex]) ^ key[keyIndex];
        messageIndex++;
        keyIndex = (keyIndex + 1) % KEY_SIZE;
    }
}

// Function to decrypt message
void decrypt(char *message, char *key) {
    int messageIndex = 0;
    int keyIndex = 0;
    while (message[messageIndex]) {
        message[messageIndex] = toupper(message[messageIndex]) ^ key[keyIndex];
        messageIndex++;
        keyIndex = (keyIndex + 1) % KEY_SIZE;
    }
}

// Function to perform encryption/decryption
void cipher(char *message, char *key, int mode) {
    if (mode == 0) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }
    else {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }
}

// Function to generate random message
void generateMessage(char *message) {
    int messageIndex = 0;
    while (messageIndex < strlen(message)) {
        message[messageIndex] = rand() % 26 + 'A';
        messageIndex++;
    }
}

int main() {
    char message[1000];
    char key[KEY_SIZE];
    int mode;
    printf("Enter message (max 1000 characters): ");
    fgets(message, sizeof(message), stdin);
    printf("Enter encryption/decryption mode (0/1): ");
    scanf("%d", &mode);
    generateKey(key);
    cipher(message, key, mode);
    return 0;
}