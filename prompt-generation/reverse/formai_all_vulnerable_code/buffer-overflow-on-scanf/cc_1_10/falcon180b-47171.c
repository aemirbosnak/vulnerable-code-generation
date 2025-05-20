//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define TRUE 1
#define FALSE 0

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate key
void generateKey(int key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to encrypt message
void encrypt(char message[100], int key[SIZE]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key[i % SIZE];
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key[i % SIZE];
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
    }
}

// Function to decrypt message
void decrypt(char message[100], int key[SIZE]) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key[i % SIZE];
            if (message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key[i % SIZE];
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
    }
}

int main() {
    char message[100];
    int key[SIZE];

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Generate key
    generateKey(key);

    // Encrypt message
    encrypt(message, key);

    // Display encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Display decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}