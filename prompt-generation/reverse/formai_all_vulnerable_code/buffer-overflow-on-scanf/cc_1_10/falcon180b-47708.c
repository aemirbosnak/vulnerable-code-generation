//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        char c = rand() % 26 + 'A';
        key[i] = c;
    }
    key[MAX_KEY_SIZE-1] = '\0';
}

// Function to encrypt a message using the key
void encrypt_message(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == MAX_KEY_SIZE) {
            j = 0;
        }
        message[i] = message[i] + key[j];
    }
}

// Function to decrypt a message using the key
void decrypt_message(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == MAX_KEY_SIZE) {
            j = 0;
        }
        message[i] = message[i] - key[j];
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // Generate a random key
    generate_key(key);

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt_message(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt_message(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}