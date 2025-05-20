//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key
#define KEY "mysecretkey"

// Function to encrypt a message
char* encrypt(char* message) {
    int length = strlen(message);
    char* encrypted = malloc(length + 1);

    // Encrypt the message
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = ((c - 65) + 26) % 26 + 65;
        }
        else if (isdigit(c)) {
            c = ((c - 48) + 10) % 10 + 48;
        }
        encrypted[i] = c;
    }
    encrypted[length] = '\0';

    return encrypted;
}

// Function to decrypt a message
char* decrypt(char* encrypted) {
    int length = strlen(encrypted);
    char* decrypted = malloc(length + 1);

    // Decrypt the message
    for (int i = 0; i < length; i++) {
        char c = encrypted[i];
        if (isalpha(c)) {
            c = ((c - 65) - 26) % 26 + 65;
        }
        else if (isdigit(c)) {
            c = ((c - 48) - 10) % 10 + 48;
        }
        decrypted[i] = c;
    }
    decrypted[length] = '\0';

    return decrypted;
}

// Function to generate a key
char* generate_key(char* key) {
    int length = strlen(key);
    char* new_key = malloc(length + 1);

    // Generate the new key
    for (int i = 0; i < length; i++) {
        char c = key[i];
        if (isalpha(c)) {
            c = ((c - 65) + 26) % 26 + 65;
        }
        else if (isdigit(c)) {
            c = ((c - 48) + 10) % 10 + 48;
        }
        new_key[i] = c;
    }
    new_key[length] = '\0';

    return new_key;
}

// Function to test the encryption and decryption
void test() {
    char* message = "Hello, World!";
    char* encrypted = encrypt(message);
    char* decrypted = decrypt(encrypted);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    test();
    return 0;
}