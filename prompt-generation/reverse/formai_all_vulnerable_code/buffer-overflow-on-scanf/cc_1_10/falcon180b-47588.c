//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *result = (char *) malloc(length + 1);
    if (result == NULL) {
        printf("Error: Failed to allocate memory for random string.\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result[i] = rand() % 26 + 'a';
    }
    result[length] = '\0';

    return result;
}

// Function to encrypt a message using a given key
void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]); // Convert message to uppercase
        message[i] = (char) ('A' + ((message[i] - 'A' + key[i % key_length] - 'A') % 26));
    }
}

// Function to decrypt a message using a given key
void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]); // Convert message to uppercase
        message[i] = (char) ('A' + ((message[i] - 'A' - key[i % key_length] + 26) % 26));
    }
}

int main() {
    char *message;
    char *key;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate random key
    key = generate_random_string(MAX_KEY_LENGTH);

    // Encrypt message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}