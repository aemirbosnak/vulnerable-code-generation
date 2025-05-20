//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int i, j;
    int message_length = strlen(message);
    int key_length = strlen(key);

    // If the key is longer than the message, truncate it
    if (key_length > message_length) {
        key_length = message_length;
    }

    // Encrypt the message
    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[j];
            if (isupper(message[i])) {
                message[i] = toupper(message[i]);
            }
            j++;
            if (j >= key_length) {
                j = 0;
            }
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char *message, char *key) {
    int i, j;
    int message_length = strlen(message);
    int key_length = strlen(key);

    // If the key is longer than the message, truncate it
    if (key_length > message_length) {
        key_length = message_length;
    }

    // Decrypt the message
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[j];
            if (isupper(message[i])) {
                message[i] = toupper(message[i]);
            }
            j++;
            if (j >= key_length) {
                j = 0;
            }
        }
    }
}

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Ask the user whether to encrypt or decrypt the message
    char choice;
    printf("Enter 'e' to encrypt or 'd' to decrypt the message: ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        // Encrypt the message
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'd' || choice == 'D') {
        // Decrypt the message
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}