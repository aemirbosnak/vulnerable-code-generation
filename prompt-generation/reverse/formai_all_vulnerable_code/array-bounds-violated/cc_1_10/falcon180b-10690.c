//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key of specified length
void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

// Function to encrypt a message using the Caesar cipher
void encrypt_message(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] - 'a' + key_length) % 26 + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_length] = '\0';
}

// Function to decrypt a message using the Caesar cipher
void decrypt_message(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < encrypted_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - 'a' - key_length + 26) % 26 + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[encrypted_length] = '\0';
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random key
    char key[MAX_KEY_LENGTH];
    generate_key(key, rand() % MAX_KEY_LENGTH + 1);

    // Generate a random message
    char message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < rand() % MAX_MESSAGE_LENGTH + 1; i++) {
        message[i] = rand() % 26 + 'a';
    }
    message[rand() % MAX_MESSAGE_LENGTH + 1] = '\0';

    // Encrypt the message
    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypt_message(message, key, encrypted_message);

    // Decrypt the message
    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt_message(encrypted_message, key, decrypted_message);

    // Print the results
    printf("Key: %s\n", key);
    printf("Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);

    return 0;
}