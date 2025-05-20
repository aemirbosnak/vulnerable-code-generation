//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

// Function to generate a random key between 1 and 25
int generateKey() {
    srand(time(NULL));
    return rand() % 25 + 1;
}

int main() {
    char message[100];
    int key;

    // Get the message from user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    key = generateKey();

    // Encrypt the message
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Get the encrypted message from user
    printf("Enter the encrypted message to decrypt: ");
    scanf("%s", message);

    // Decrypt the message using the same key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}