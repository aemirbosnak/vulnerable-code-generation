//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

// function to generate a random key
void generate_key(unsigned char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// function to encrypt a message using the key
void encrypt(unsigned char* message, unsigned char* key, unsigned char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key[i % KEY_SIZE];
    }
}

// function to decrypt an encrypted message using the key
void decrypt(unsigned char* encrypted_message, unsigned char* key, unsigned char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
}

// main function
int main() {
    unsigned char key[KEY_SIZE];
    unsigned char message[100];
    unsigned char encrypted_message[100];
    unsigned char decrypted_message[100];

    // generate a random key
    generate_key(key);

    // prompt the user for a message to encrypt
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // decrypt the encrypted message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}