//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                temp = message[i] + key;
                if (temp > 'Z') {
                    temp = temp - 26;
                }
                message[i] = temp;
            } else {
                temp = message[i] + key;
                if (temp > 'z') {
                    temp = temp - 26;
                }
                message[i] = temp;
            }
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int key) {
    int i, j;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                temp = message[i] - key;
                if (temp < 'A') {
                    temp = temp + 26;
                }
                message[i] = temp;
            } else {
                temp = message[i] - key;
                if (temp < 'a') {
                    temp = temp + 26;
                }
                message[i] = temp;
            }
        }
    }
}

// Function to generate a random key
int generate_key() {
    int key;
    key = rand() % 26;
    return key;
}

// Function to encrypt and decrypt the message using Caesar cipher
void caesar_cipher(char *message, int key) {
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_SIZE];
    int key;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Generate a random key
    key = generate_key();

    // Encrypt and decrypt the message
    caesar_cipher(message, key);

    return 0;
}