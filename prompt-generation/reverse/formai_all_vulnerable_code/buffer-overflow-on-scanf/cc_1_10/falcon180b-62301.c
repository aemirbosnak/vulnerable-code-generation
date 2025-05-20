//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define ALPHABET_SIZE 26

// Function to encrypt message using Caesar cipher
void encrypt(char* message, int key) {
    int i;
    for(i=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % ALPHABET_SIZE + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % ALPHABET_SIZE + 'a';
            }
        }
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char* message, int key) {
    int i;
    for(i=0; message[i]!='\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
            }
        }
    }
}

// Function to generate a random key between 0 and 25
int generateKey() {
    return rand() % ALPHABET_SIZE;
}

int main() {
    char message[1000];
    int key;

    // Generate a random key
    key = generateKey();

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%[^\n]", message);

    // Encrypt message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}