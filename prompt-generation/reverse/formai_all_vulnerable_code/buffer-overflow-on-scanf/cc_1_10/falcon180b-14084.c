//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

// Function to generate a random key
void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    char encrypted_message[strlen(message)];
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        encrypted_message[i] = message[i] ^ key[j];
    }
    encrypted_message[strlen(message)] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt a message
void decrypt(char *encrypted_message, char *key) {
    char decrypted_message[strlen(encrypted_message)];
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++, j++) {
        if (j == KEY_SIZE) {
            j = 0;
        }
        decrypted_message[i] = encrypted_message[i] ^ key[j];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000], key[KEY_SIZE + 1];
    generate_key(key);
    printf("Key: %s\n", key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);
    printf("\nEnter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(message, key);
    return 0;
}