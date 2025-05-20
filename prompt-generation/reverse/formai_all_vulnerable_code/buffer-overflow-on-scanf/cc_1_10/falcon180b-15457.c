//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to initialize the key with random values
void initKey(char key[KEY_SIZE]) {
    for(int i=0; i<KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt the message using the key
void encrypt(char message[100], char key[KEY_SIZE], char encrypted[100]) {
    int j = 0;
    for(int i=0; i<strlen(message); i++) {
        if(isalpha(message[i])) {
            encrypted[j++] = (message[i] + key[i%KEY_SIZE]) % 26 + 'A';
        } else {
            encrypted[j++] = message[i];
        }
    }
    encrypted[j] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char encrypted[100], char key[KEY_SIZE], char decrypted[100]) {
    int j = 0;
    for(int i=0; i<strlen(encrypted); i++) {
        if(isalpha(encrypted[i])) {
            decrypted[j++] = (encrypted[i] - key[i%KEY_SIZE] + 26) % 26 + 'A';
        } else {
            decrypted[j++] = encrypted[i];
        }
    }
    decrypted[j] = '\0';
}

int main() {
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    char key[KEY_SIZE];
    initKey(key);

    char encrypted[100];
    encrypt(message, key, encrypted);

    printf("Encrypted message: %s\n", encrypted);

    char decrypted[100];
    decrypt(encrypted, key, decrypted);

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}