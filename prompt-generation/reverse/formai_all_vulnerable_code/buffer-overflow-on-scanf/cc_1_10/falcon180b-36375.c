//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given string using a key
void encrypt(char* input, char* key) {
    int i, j, k, n = strlen(input);

    // Calculate the length of the key
    int key_length = strlen(key);

    // Initialize the substitution table
    char substitution_table[26];
    for (i = 0; i < 26; i++) {
        substitution_table[i] = i + 'A';
    }

    // Encrypt the message
    for (i = 0; i < n; i++) {
        if (isalpha(input[i])) {
            input[i] = substitution_table[input[i] - 'A'] + key[i % key_length] - 'A';
        }
    }
}

// Function to decrypt the given string using a key
void decrypt(char* input, char* key) {
    int i, j, k, n = strlen(input);

    // Calculate the length of the key
    int key_length = strlen(key);

    // Initialize the substitution table
    char substitution_table[26];
    for (i = 0; i < 26; i++) {
        substitution_table[i] = i + 'A';
    }

    // Decrypt the message
    for (i = 0; i < n; i++) {
        if (isalpha(input[i])) {
            input[i] = substitution_table[(input[i] - key[i % key_length] + 26) % 26] - 'A';
        }
    }
}

// Function to remove whitespace from the given string
void remove_whitespace(char* input) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (!isspace(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int main() {
    char input[1000];
    char key[100];

    // Get the input message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", input);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Remove whitespace from the input message
    remove_whitespace(input);

    // Encrypt the message using the key
    encrypt(input, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", input);

    // Decrypt the message using the key
    decrypt(input, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", input);

    return 0;
}