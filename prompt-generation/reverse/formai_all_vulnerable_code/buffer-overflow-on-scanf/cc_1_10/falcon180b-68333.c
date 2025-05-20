//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a random number between 0 and n-1
int randInt(int n) {
    return rand() % n;
}

// Function to encrypt the message
void encrypt(char message[], int key[], int size) {
    int i, j;
    for(i=0; i<size; i++) {
        message[i] = message[i] + key[i];
        if(message[i] > 'z') {
            message[i] = message[i] - 26;
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], int key[], int size) {
    int i, j;
    for(i=0; i<size; i++) {
        message[i] = message[i] - key[i];
        if(message[i] < 'a') {
            message[i] = message[i] + 26;
        }
    }
}

// Function to generate a random key
void generateKey(int key[], int size) {
    int i;
    for(i=0; i<size; i++) {
        key[i] = randInt(26) + 'a';
    }
}

int main() {
    char message[SIZE];
    int key[SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generateKey(key, SIZE);

    // Encrypt the message
    encrypt(message, key, SIZE);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Get the encrypted message from the user
    printf("Enter the encrypted message to decrypt: ");
    scanf("%s", message);

    // Decrypt the message
    decrypt(message, key, SIZE);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}