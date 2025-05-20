//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the alphabet
#define ALPHABET_SIZE 26
char alphabet[ALPHABET_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

// Define the Caesar cipher function
char caesar_cipher(char c, int key) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return alphabet[((int)c - 65 + key) % ALPHABET_SIZE];
        } else {
            return alphabet[((int)c - 97 + key) % ALPHABET_SIZE];
        }
    } else {
        return c;
    }
}

// Define the Vigenere cipher function
void vigenere_cipher(char* message, char* key, char* result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            result[i] = caesar_cipher(message[i], toupper(key[i % key_length]) - 65);
        } else {
            result[i] = message[i];
        }
    }
}

// Define the main function
int main() {
    char message[1000], key[1000];
    char result[1000];

    // Get the message and key from the user
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove the newline character from the message and key
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    // Perform the Vigenere cipher
    vigenere_cipher(message, key, result);

    // Print the result
    printf("Encrypted message: %s\n", result);

    return 0;
}