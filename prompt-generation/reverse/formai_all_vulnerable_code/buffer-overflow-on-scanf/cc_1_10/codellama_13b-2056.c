//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
// Cryptography Implementation Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Declarations
void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

// Main Function
int main() {
    char message[100];
    char key[100];
    int choice;

    printf("Enter the message: ");
    fgets(message, 100, stdin);
    printf("Enter the key: ");
    fgets(key, 100, stdin);

    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(message, key);
    } else if (choice == 2) {
        decrypt(message, key);
    } else {
        printf("Invalid choice.");
        return 1;
    }

    return 0;
}

// Encryption Function
void encrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key[i % strlen(key)];
    }
}

// Decryption Function
void decrypt(char *message, char *key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] = message[i] - key[i % strlen(key)];
    }
}