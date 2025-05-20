//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 1024

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, int message_size, char* key) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]) - 'A' + (key[i % strlen(key)] - 'A');
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char* message, int message_size, char* key) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]) - 'A' - (key[i % strlen(key)] - 'A') + 'A';
        }
    }
}

// Function to encrypt and decrypt the message using the key
void transform(char* message, int message_size, char* key) {
    encrypt(message, message_size, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, message_size, key);
    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_BLOCK_SIZE];
    char key[MAX_KEY_SIZE];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Transform the message using the key
    transform(message, strlen(message), key);

    return 0;
}