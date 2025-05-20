//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ALPHABET_SIZE 26

// Function to encrypt message using Caesar cipher
void encrypt(char* message, int key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1]; // Add one for null terminator
    encrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                encrypted_message[i] = (c + key - 65) % ALPHABET_SIZE + 65;
            } else {
                encrypted_message[i] = (c + key - 97) % ALPHABET_SIZE + 97;
            }
        } else {
            encrypted_message[i] = c;
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt message using Caesar cipher
void decrypt(char* message, int key) {
    int message_length = strlen(message);
    char decrypted_message[message_length + 1]; // Add one for null terminator
    decrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                decrypted_message[i] = (c - key - 65) % ALPHABET_SIZE + 65;
            } else {
                decrypted_message[i] = (c - key - 97) % ALPHABET_SIZE + 97;
            }
        } else {
            decrypted_message[i] = c;
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    printf("Enter a message: ");
    scanf("%s", message);

    int key;
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}