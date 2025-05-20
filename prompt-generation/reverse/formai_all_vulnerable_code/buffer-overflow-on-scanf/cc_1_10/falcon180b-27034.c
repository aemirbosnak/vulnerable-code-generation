//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random key
void generate_key(int key[MAX_SIZE]) {
    int i;
    srand(time(0));
    for (i = 0; i < MAX_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt(char message[MAX_SIZE], int key[MAX_SIZE]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key[i % MAX_SIZE]) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key[i % MAX_SIZE]) % 26 + 'A';
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char message[MAX_SIZE], int key[MAX_SIZE]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key[i % MAX_SIZE] + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key[i % MAX_SIZE] + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[MAX_SIZE];
    int key[MAX_SIZE];
    int choice;
    int i;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Generate the key
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}