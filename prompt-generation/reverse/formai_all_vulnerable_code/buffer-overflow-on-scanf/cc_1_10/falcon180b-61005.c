//Falcon-180B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Function to encrypt the message
void encrypt(char *message, int key) {
    int i, j;
    char temp;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) (((int) message[i] + key - 97) % 26 + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) (((int) message[i] + key - 65) % 26 + 65);
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int i, j;
    char temp;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) (((int) message[i] - key - 97) % 26 + 97);
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) (((int) message[i] - key - 65) % 26 + 65);
        }
    }
}

// Function to print the message
void print_message(char *message) {
    printf("Message: %s\n", message);
}

int main() {
    char message[SIZE];
    int key;

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key for encryption/decryption: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}