//Falcon-180B DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the key for encryption
#define KEY "I_LOVE_PROGRAMMING"

// Function to encrypt the message
void encrypt(char* message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 65 + j) % 26 + 65;
            } else {
                message[i] = (message[i] - 97 + j) % 26 + 97;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char* message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 65 - j + 26) % 26 + 65;
            } else {
                message[i] = (message[i] - 97 - j + 26) % 26 + 97;
            }
        }
    }
}

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(KEY); i++) {
        key[i] = rand() % 26 + 97;
    }
}

// Function to get user input for message and key
void get_input(char* message, char* key) {
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter the key: ");
    scanf("%s", key);
}

int main() {
    srand(time(NULL));

    char message[1000];
    char key[1000];

    // Get user input for message and key
    get_input(message, key);

    // Generate a random key if none is provided
    if (strcmp(key, "") == 0) {
        generate_key(key);
        printf("Generated key: %s\n", key);
    }

    // Encrypt the message
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}