//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

// Function to shift a character by a given amount
char shift(char c, int amount) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return 'A' + ((c - 'A' + amount) % 26);
        } else {
            return 'a' + ((c - 'a' + amount) % 26);
        }
    } else {
        return c;
    }
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int i = 0;
    int j = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = shift(c, (int)key[j] - 'A');
            } else {
                c = shift(c, (int)key[j] - 'a');
            }
            message[i] = c;
        }
        i++;
        j++;
        if (j >= strlen(key)) {
            j = 0;
        }
    }
}

// Function to decrypt a message using a key
void decrypt(char* message, char* key) {
    int i = 0;
    int j = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = shift(c, 26 - (int)key[j] - 'A');
            } else {
                c = shift(c, 26 - (int)key[j] - 'a');
            }
            message[i] = c;
        }
        i++;
        j++;
        if (j >= strlen(key)) {
            j = 0;
        }
    }
}

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = 'A' + rand() % 26;
    }
    key[MAX_KEY_LENGTH] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get message from user
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Remove newline character from message
    int message_length = strlen(message);
    if (message[message_length - 1] == '\n') {
        message[message_length - 1] = '\0';
    }

    // Get key from user
    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    // Remove newline character from key
    if (key[strlen(key) - 1] == '\n') {
        key[strlen(key) - 1] = '\0';
    }

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}