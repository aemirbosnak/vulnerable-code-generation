//Falcon-180B DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + key - 65);
            }
            else {
                message[i] = toupper(message[i] + key - 97);
            }
        }
        i++;
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] - key - 65);
            }
            else {
                message[i] = toupper(message[i] - key - 97);
            }
        }
        i++;
    }
}

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    int i = 0;
    while (i < MAX_KEY_LENGTH) {
        key[i] = rand() % 26 + 65;
        i++;
    }
    key[i] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    encrypt(message, strlen(key));

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, strlen(key));

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}