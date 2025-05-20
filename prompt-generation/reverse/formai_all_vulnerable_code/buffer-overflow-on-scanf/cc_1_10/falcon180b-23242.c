//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to generate a random key
void generate_key(char key[MAX_SIZE]) {
    srand(time(NULL));
    int i;
    for(i = 0; i < MAX_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt_message(char message[MAX_SIZE], char key[MAX_SIZE]) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            message[i] = (message[i] - 'a' + key[i % strlen(key)]) % 26 + 'a';
        } else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt the message using the key
void decrypt_message(char message[MAX_SIZE], char key[MAX_SIZE]) {
    int i;
    for(i = 0; i < strlen(message); i++) {
        if(isalpha(message[i])) {
            message[i] = (message[i] - 'a' - key[i % strlen(key)]) % 26 + 'a';
        } else {
            message[i] = message[i];
        }
    }
}

// Function to display the encrypted message
void display_encrypted_message(char message[MAX_SIZE]) {
    printf("Encrypted message: %s\n", message);
}

// Function to display the decrypted message
void display_decrypted_message(char message[MAX_SIZE]) {
    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt_message(message, key);

    // Display the encrypted message
    display_encrypted_message(message);

    // Get the key from the user
    printf("Enter the key to decrypt: ");
    scanf("%s", key);

    // Decrypt the message using the key
    decrypt_message(message, key);

    // Display the decrypted message
    display_decrypted_message(message);

    return 0;
}