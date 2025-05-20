//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key, it's a number, you can change it!
#define KEY 42

// The Caesar cipher function, it takes a character and shifts it by the key value
char encrypt_caesar(char c) {
    return (c + KEY) % 128;
}

// The Vigenere cipher function, it takes a character and a key character and shifts it by the key value
char encrypt_vigenere(char c, char key) {
    return (c + key - 2 * 'a') % 26 + 'a';
}

// The main function, where the magic happens
int main() {
    // Let's print a welcome message, just to be friendly
    printf("Welcome to our encryption playground!\n");

    // Let's ask the user for a message to encrypt
    char message[100];
    printf("Enter your secret message: ");
    gets(message);

    // Let's show the user the original message
    printf("Original message: %s\n", message);

    // Now, let's encrypt the message using the Caesar cipher
    char encrypted_caesar[100];
    for (int i = 0; message[i] != '\0'; i++) {
        encrypted_caesar[i] = encrypt_caesar(message[i]);
    }

    // Let's show the user the encrypted message using the Caesar cipher
    printf("Caesar cipher: %s\n", encrypted_caesar);

    // Let's encrypt the message again, this time using the Vigenere cipher
    char encrypted_vigenere[100];
    char key[] = "SECRET";
    int key_index = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        encrypted_vigenere[i] = encrypt_vigenere(message[i], key[key_index]);
        key_index = (key_index + 1) % strlen(key);
    }

    // Let's show the user the encrypted message using the Vigenere cipher
    printf("Vigenere cipher: %s\n", encrypted_vigenere);

    return 0;
}