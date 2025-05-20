//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using a Caesar cipher with a given key
void caesar_encrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) ((int) message[i] + key - 97);
            if (message[i] > 'z') {
                message[i] = (char) ((int) message[i] - 26);
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) ((int) message[i] + key - 65);
            if (message[i] > 'Z') {
                message[i] = (char) ((int) message[i] - 26);
            }
        }
        i++;
    }
}

// Function to decrypt the message using a Caesar cipher with a given key
void caesar_decrypt(char* message, int key) {
    int i = 0;
    while (message[i]!= '\0') {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) ((int) message[i] - key - 97);
            if (message[i] < 'a') {
                message[i] = (char) ((int) message[i] + 26);
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) ((int) message[i] - key - 65);
            if (message[i] < 'A') {
                message[i] = (char) ((int) message[i] + 26);
            }
        }
        i++;
    }
}

// Function to generate a random key for the Caesar cipher
int generate_key() {
    int key = rand() % 26;
    while (key < 1) {
        key = rand() % 26;
    }
    return key;
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    int key = generate_key();

    // Encrypt the message using the key
    caesar_encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the same key
    caesar_decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}