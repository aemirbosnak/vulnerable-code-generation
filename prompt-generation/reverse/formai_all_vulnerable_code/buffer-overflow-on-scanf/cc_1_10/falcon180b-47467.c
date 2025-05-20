//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

// Function to generate a random key of length key_length
void generate_key(char key[], int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

// Function to encrypt a message using the key
void encrypt(char message[], char key[], char encrypted_message[]) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = (message[i] + key[i % strlen(key)]) % 26 + 'a';
    }
    encrypted_message[strlen(message)] = '\0';
}

// Function to decrypt an encrypted message using the key
void decrypt(char encrypted_message[], char key[], char decrypted_message[]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = (encrypted_message[i] - key[i % strlen(key)]) % 26 + 'a';
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char key[MAX_KEY_LENGTH];
    generate_key(key, MAX_KEY_LENGTH);

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}