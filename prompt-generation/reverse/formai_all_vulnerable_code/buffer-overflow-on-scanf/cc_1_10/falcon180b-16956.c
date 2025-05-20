//Falcon-180B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt the message using Caesar Cipher
void encrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 65 + 13) % 26) + 65;
            } else {
                message[i] = ((message[i] - 97 + 13) % 26) + 97;
            }
        }
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 65 - 13) % 26) + 65;
            } else {
                message[i] = ((message[i] - 97 - 13) % 26) + 97;
            }
        }
    }
}

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < strlen(KEY); i++) {
        key[i] = (rand() % 26) + 65;
    }
    key[strlen(KEY)] = '\0';
}

int main() {
    char message[1000];
    char key[1000];

    // Generate a random key
    generate_key(key);

    // Get the message from the user
    printf("Enter your message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}