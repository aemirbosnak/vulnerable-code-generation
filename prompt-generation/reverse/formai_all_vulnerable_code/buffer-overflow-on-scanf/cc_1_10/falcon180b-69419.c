//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 64
#define MAX_BLOCK_SIZE 64

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt a message using a key
void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[MAX_BLOCK_SIZE];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (message[i] + key[i % MAX_KEY_SIZE]) % 26 + 'a';
            j++;
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt an encrypted message using a key
void decrypt(char *encrypted_message, char *key) {
    int i, j;
    char decrypted_message[MAX_BLOCK_SIZE];
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = (encrypted_message[i] - key[i % MAX_KEY_SIZE] + 26) % 26 + 'a';
            j++;
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_BLOCK_SIZE];
    char key[MAX_KEY_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key for encryption: ");
    scanf("%s", key);
    generate_key(key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}