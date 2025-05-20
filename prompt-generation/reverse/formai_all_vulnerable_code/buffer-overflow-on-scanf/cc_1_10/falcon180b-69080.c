//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt message using Caesar cipher
void encrypt(char message[], char key[], int key_length) {
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = message[i] + key[j % key_length] - 65;
            } else {
                message[i] = message[i] + key[j % key_length] - 97;
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char message[], char key[], int key_length) {
    int i, j, k;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = message[i] - key[j % key_length] + 65;
            } else {
                message[i] = message[i] - key[j % key_length] + 97;
            }
        } else {
            message[i] = message[i];
        }
    }
}

// Function to generate a random key of given length
void generate_key(char key[], int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH];
    int message_length, key_length;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Get key length from user
    printf("Enter key length: ");
    scanf("%d", &key_length);

    // Generate random key
    generate_key(key, key_length);

    // Encrypt message
    encrypt(message, key, key_length);

    // Display encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key, key_length);

    // Display decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}