//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_KEY_LENGTH 1024

// Encryption function
void encryption(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *encrypted_message = (char *)malloc(sizeof(char) * (message_len + 1));

    // Initialize the random number generator
    srand(time(NULL));

    // Iterate through the message and encrypt each character
    for (int i = 0; i < message_len; i++) {
        // Get the ASCII value of the current character
        int ascii_val = (int)message[i];

        // Generate a random number between 0 and 25
        int random_number = rand() % 26;

        // Encrypt the character
        ascii_val += random_number;

        // Handle wrap-around
        if (ascii_val > 126) {
            ascii_val -= 94;
        }

        // Add the encrypted character to the encrypted message
        encrypted_message[i] = (char)ascii_val;
    }

    // Add a null terminator to the encrypted message
    encrypted_message[message_len] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Decryption function
void decryption(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *decrypted_message = (char *)malloc(sizeof(char) * (message_len + 1));

    // Iterate through the message and decrypt each character
    for (int i = 0; i < message_len; i++) {
        // Get the ASCII value of the current character
        int ascii_val = (int)message[i];

        // Decrypt the character
        ascii_val -= (int)key[i % key_len];

        // Handle wrap-around
        if (ascii_val < 32) {
            ascii_val += 94;
        }

        // Add the decrypted character to the decrypted message
        decrypted_message[i] = (char)ascii_val;
    }

    // Add a null terminator to the decrypted message
    decrypted_message[message_len] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    // Get the message to encrypt
    char message[] = "Hello, World!";

    // Get the encryption key
    char key[] = "secret_key";

    // Encrypt the message
    encryption(message, key);

    // Decrypt the message
    decryption(message, key);

    return 0;
}