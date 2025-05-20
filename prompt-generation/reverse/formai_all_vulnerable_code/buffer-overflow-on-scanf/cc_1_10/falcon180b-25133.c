//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1000

// Function to encrypt message using Caesar Cipher
void encrypt(char* message, int key) {
    int i = 0;
    char encrypted_message[MAX_MESSAGE_SIZE];

    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = (char) (((int) message[i] + key - 65) % 26 + 65);
            } else {
                encrypted_message[i] = (char) (((int) message[i] + key - 97) % 26 + 97);
            }
        } else {
            encrypted_message[i] = message[i];
        }
        i++;
    }
    encrypted_message[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt message using Caesar Cipher
void decrypt(char* message, int key) {
    int i = 0;
    char decrypted_message[MAX_MESSAGE_SIZE];

    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = (char) (((int) message[i] - 65 - key + 26) % 26 + 65);
            } else {
                decrypted_message[i] = (char) (((int) message[i] - 97 - key + 26) % 26 + 97);
            }
        } else {
            decrypted_message[i] = message[i];
        }
        i++;
    }
    decrypted_message[i] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

// Function to generate a random key
int generate_key() {
    int key = rand() % MAX_KEY_SIZE;
    return key;
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    int key;

    // Get message from user
    printf("Enter your message: ");
    scanf("%s", message);

    // Generate a random key
    key = generate_key();

    // Encrypt the message using Caesar Cipher
    encrypt(message, key);

    // Decrypt the encrypted message back to original message
    decrypt(message, key);

    return 0;
}