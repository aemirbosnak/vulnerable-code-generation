//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message
void encrypt(char *message, int key) {
    int len = strlen(message);
    int i;
    for(i = 0; i < len; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            }
            else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

// Function to decrypt message
void decrypt(char *message, int key) {
    int len = strlen(message);
    int i;
    for(i = 0; i < len; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            }
            else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

// Function to generate key
int generateKey(int min, int max) {
    int key;
    do {
        key = rand() % (max - min + 1) + min;
    } while(key % 26 == 0);
    return key;
}

int main() {
    char message[100];
    int key;

    // Generate key
    key = generateKey(1, 25);

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Encrypt message
    encrypt(message, key);

    // Display encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Display decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}