//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, int key) {
    int length = strlen(message);
    int i = 0;

    // Loop through each character in the message
    for (i = 0; i < length; i++) {
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

// Function to decrypt the message
void decrypt(char* message, int key) {
    int length = strlen(message);
    int i = 0;

    // Loop through each character in the message
    for (i = 0; i < length; i++) {
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

// Function to generate a random key
int generateKey() {
    int key = rand() % 26;
    return key;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    int key = generateKey(); // Generate a random key
    char message[100]; // Message to be encrypted and decrypted

    // Prompt the user to enter a message
    printf("Enter a message to be encrypted: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}