//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using the Caesar cipher
void encrypt(char* message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}

// Function to decrypt the message using the Caesar cipher
void decrypt(char* message, int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
            }
        }
    }
}

// Function to generate a random key
int generate_key() {
    return rand() % 26;
}

int main() {
    char message[100];
    int key;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    key = generate_key();

    // Encrypt the message using the Caesar cipher
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the Caesar cipher
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}