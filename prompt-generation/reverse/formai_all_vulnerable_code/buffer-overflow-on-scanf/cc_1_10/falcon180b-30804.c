//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the alphabet
#define ALPHABET_SIZE 26
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

// Define the key
#define KEY_SIZE 5
char key[] = "secret";

// Define the mapping of the alphabet to the key
char mapping[ALPHABET_SIZE];

// Initialize the mapping
void initMapping() {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        mapping[i] = key[i % KEY_SIZE];
    }
}

// Encrypt the message
void encrypt(char message[], char encrypted[]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            int index = tolower(message[i]) - 'a';
            encrypted[i] = mapping[index];
        } else {
            encrypted[i] = message[i];
        }
    }
}

// Decrypt the message
void decrypt(char encrypted[], char decrypted[]) {
    int i;
    for (i = 0; encrypted[i]!= '\0'; i++) {
        if (isalpha(encrypted[i])) {
            int index = tolower(encrypted[i]) - 'a';
            decrypted[i] = alphabet[index];
        } else {
            decrypted[i] = encrypted[i];
        }
    }
}

int main() {
    char message[100];
    char encrypted[100];
    char decrypted[100];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Initialize the mapping
    initMapping();

    // Encrypt the message
    encrypt(message, encrypted);

    // Decrypt the message
    decrypt(encrypted, decrypted);

    // Print the results
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}