//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000 // size of the array

// Function to encrypt the message using a key
void encrypt(char message[], int key) {
    int i, j;
    char temp;

    // Traverse through all characters
    for (i = 0; message[i]!= '\0'; i++) {
        // Encrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }

        // Encrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
    }
}

// Function to decrypt the message using a key
void decrypt(char message[], int key) {
    int i, j;
    char temp;

    // Traverse through all characters
    for (i = 0; message[i]!= '\0'; i++) {
        // Decrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }

        // Decrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        }
    }
}

// Function to generate a key of given length
void generateKey(int length, char key[]) {
    int i;

    // Initialize the key array with random characters
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Main function
int main() {
    char message[SIZE], key[100];
    int i, length;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%[^\n]", message);

    // Get the length of the key
    printf("Enter the length of the key: ");
    scanf("%d", &length);

    // Generate the key
    generateKey(length, key);

    // Encrypt the message using the key
    encrypt(message, key[0]);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key[0]);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}