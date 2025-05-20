//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the size of the key
#define KEY_SIZE 8

// Define the size of the block
#define BLOCK_SIZE 8

// Define the size of the alphabet
#define ALPHABET_SIZE 26

// Define the alphabet
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Define the function prototypes
void generate_key(char* key);
void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main() {
    char message[1000];
    char key[KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);

    // Generate the key
    generate_key(key);

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

// Function to generate the key
void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = alphabet[rand() % ALPHABET_SIZE];
    }
}

// Function to encrypt the message
void encrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - 'A' + 'a';
        }
        if (isupper(message[i])) {
            message[i] = message[i] + 'A' - 'a';
        }
        message[i] = message[i] + key[j];
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - 'A' + 'a';
        }
        if (isupper(message[i])) {
            message[i] = message[i] + 'A' - 'a';
        }
        message[i] = message[i] - key[j];
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }
}