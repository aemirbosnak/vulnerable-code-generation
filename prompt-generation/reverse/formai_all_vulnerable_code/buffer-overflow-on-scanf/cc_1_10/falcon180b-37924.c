//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char message[]) {
    int len = strlen(message);
    int key = 3; // Key for encryption
    char encrypted_message[len]; // Encrypted message

    // Encrypting the message
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = message[i] + key;
                if (encrypted_message[i] > 'Z') {
                    encrypted_message[i] = encrypted_message[i] - 26;
                }
            }
            else {
                encrypted_message[i] = message[i] + key;
                if (encrypted_message[i] > 'z') {
                    encrypted_message[i] = encrypted_message[i] - 26;
                }
            }
        }
        else {
            encrypted_message[i] = message[i];
        }
    }

    // Printing the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message
void decrypt(char message[]) {
    int len = strlen(message);
    int key = 3; // Key for decryption
    char decrypted_message[len]; // Decrypted message

    // Decrypting the message
    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = message[i] - key;
                if (decrypted_message[i] < 'A') {
                    decrypted_message[i] = decrypted_message[i] + 26;
                }
            }
            else {
                decrypted_message[i] = message[i] - key;
                if (decrypted_message[i] < 'a') {
                    decrypted_message[i] = decrypted_message[i] + 26;
                }
            }
        }
        else {
            decrypted_message[i] = message[i];
        }
    }

    // Printing the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100]; // Message to be encrypted/decrypted

    // Getting the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Encrypting the message
    encrypt(message);

    // Decrypting the message
    decrypt(message);

    return 0;
}