//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

// Function to encrypt the message using the given key
void encrypt(char *message, char *key) {
    int i, j;
    int key_size = strlen(key);
    int message_size = strlen(message);

    // Pad the message with spaces to make it a multiple of the key size
    while (message_size % key_size!= 0) {
        strcat(message, " ");
        message_size++;
    }

    // Convert the key to uppercase
    for (i = 0; i < key_size; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the message
    for (i = 0, j = 0; i < message_size; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A') + (key[j] - 'A')) % 26;
            } else {
                message[i] = 'a' + ((message[i] - 'a') + (key[j] - 'A')) % 26;
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt the message using the given key
void decrypt(char *message, char *key) {
    int i, j;
    int key_size = strlen(key);
    int message_size = strlen(message);

    // Convert the key to uppercase
    for (i = 0; i < key_size; i++) {
        key[i] = toupper(key[i]);
    }

    // Decrypt the message
    for (i = 0, j = 0; i < message_size; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((message[i] - 'A' - (key[j] - 'A')) + 26) % 26;
            } else {
                message[i] = 'a' + ((message[i] - 'a' - (key[j] - 'A')) + 26) % 26;
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to generate a random key of the given length
void generate_key(char *key, int length) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (i = 0; i < length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Get the encrypted message from the user
    printf("Enter the encrypted message: ");
    scanf("%s", message);

    // Decrypt the message
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}