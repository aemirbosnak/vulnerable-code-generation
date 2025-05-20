//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[1000];
    encrypted_message[0] = '\0';
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            encrypted_message[i] = (message[i] + key[i % KEY_LENGTH]) % 26 + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt a message
void decrypt(char *message, char *key) {
    int i, j;
    char decrypted_message[1000];
    decrypted_message[0] = '\0';
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            decrypted_message[i] = (message[i] - key[i % KEY_LENGTH] + 26) % 26 + 'a';
        } else {
            decrypted_message[i] = message[i];
        }
    }
    decrypted_message[strlen(message)] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000], key[KEY_LENGTH + 1];
    srand(time(NULL));
    generate_key(key);
    printf("Key: %s\n", key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(message, key);
    return 0;
}