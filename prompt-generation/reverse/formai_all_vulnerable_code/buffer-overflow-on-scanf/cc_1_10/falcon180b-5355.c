//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024
#define MAX_MESSAGE_LENGTH 1024

// Function to convert a string to uppercase
void string_to_uppercase(char* str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to generate a random key
void generate_key(char* key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

// Function to encrypt a message using Caesar cipher
void encrypt(char* message, char* key, char* encrypted_message) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) ((int) message[i] + (int) key[i % strlen(key)] - 65);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[i] = '\0';
}

// Function to decrypt a message using Caesar cipher
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i;
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (char) ((int) encrypted_message[i] - (int) key[i % strlen(key)] + 65);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[i] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message
    printf("Encrypted message: ");
    encrypt(message, key, encrypted_message);
    printf("%s\n", encrypted_message);

    // Decrypt the message
    printf("Decrypted message: ");
    decrypt(encrypted_message, key, decrypted_message);
    printf("%s\n", decrypted_message);

    return 0;
}