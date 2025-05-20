//Falcon-180B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int length = strlen(message);
    if (length == 1) {
        printf("%c", message[0]);
        return;
    }

    int mid = length / 2;
    encrypt(message, key);
    encrypt(message + mid, key);

    char temp = message[mid];
    message[mid] = message[length - 1];
    message[length - 1] = temp;
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int length = strlen(message);
    if (length == 1) {
        printf("%c", message[0]);
        return;
    }

    int mid = length / 2;
    decrypt(message, key);
    decrypt(message + mid, key);

    char temp = message[mid];
    message[mid] = message[length - 1];
    message[length - 1] = temp;
}

// Function to generate a random key
int generate_key() {
    return rand() % 26 + 1;
}

int main() {
    int key = generate_key();
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}