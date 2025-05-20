//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 1000
#define MAX_KEY_LENGTH 100

// Function to shift the ASCII value of a character by a given amount
char shift(char c, int shift) {
    if (isupper(c)) {
        return (char) (((int) c - 65 + shift) % 26 + 65);
    } else if (islower(c)) {
        return (char) (((int) c - 97 + shift) % 26 + 97);
    } else {
        return c;
    }
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int i, j, key_index = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i], key[key_index] - 'a');
            key_index = (key_index + 1) % strlen(key);
        }
    }
}

// Function to decrypt a message using a key
void decrypt(char* message, char* key) {
    int i, j, key_index = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = shift(message[i], 'a' - key[key_index]);
            key_index = (key_index + 1) % strlen(key);
        }
    }
}

int main() {
    char message[MAX_INPUT], key[MAX_KEY_LENGTH];
    int message_length, key_length;

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Validate the key length
    for (key_length = 0; key[key_length]!= '\0'; key_length++) {
        if (!isalpha(key[key_length])) {
            printf("Error: Key must only contain letters.\n");
            return 1;
        }
    }

    // Validate the message length
    message_length = strlen(message);
    if (message_length > MAX_INPUT) {
        printf("Error: Message is too long.\n");
        return 1;
    }

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}