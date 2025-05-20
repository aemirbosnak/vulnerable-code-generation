//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_MSG_SIZE 1024

// Function to generate a random key
void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((message[i] + key[i % strlen(key)]) % 26 + 'A');
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (char) ((encrypted_message[i] - key[i % strlen(key)]) % 26 + 'A');
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

// Function to print the encrypted and decrypted messages
void print_messages(char* message, char* encrypted_message, char* decrypted_message) {
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    srand(time(NULL));
    char key[MAX_KEY_SIZE];
    char message[MAX_MSG_SIZE];
    char encrypted_message[MAX_MSG_SIZE];
    char decrypted_message[MAX_MSG_SIZE];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Decrypt the message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Print the encrypted and decrypted messages
    print_messages(message, encrypted_message, decrypted_message);

    return 0;
}