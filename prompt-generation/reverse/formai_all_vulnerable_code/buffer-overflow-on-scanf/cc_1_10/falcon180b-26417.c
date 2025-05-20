//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 64

// Function to generate a random key of specified length
void generate_key(char* key, int length) {
    for(int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt the given message using the key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];
    int encrypted_message_index = 0;

    // Loop through each character in the message
    for(int i = 0; i < message_length; i++) {
        // If the character is a letter, encrypt it
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + (int)key[i % strlen(key)]) % 26 + 'a';
        }
        encrypted_message[encrypted_message_index++] = message[i];
    }
    encrypted_message[encrypted_message_index] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the given message using the key
void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    char decrypted_message[message_length + 1];
    int decrypted_message_index = 0;

    // Loop through each character in the message
    for(int i = 0; i < message_length; i++) {
        // If the character is a letter, decrypt it
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - (int)key[i % strlen(key)] + 26) % 26 + 'a';
        }
        decrypted_message[decrypted_message_index++] = message[i];
    }
    decrypted_message[decrypted_message_index] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[1000];

    // Generate a random key
    generate_key(key, rand() % MAX_KEY_SIZE + 1);

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the encrypted message using the same key
    decrypt(message, key);

    return 0;
}