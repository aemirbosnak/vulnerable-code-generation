//Falcon-180B DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        message[i] = message[i] + key;
        if (message[i] > 'z') {
            message[i] = message[i] - 26;
        } else if (message[i] < 'a') {
            message[i] = message[i] + 26;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        message[i] = message[i] - key;
        if (message[i] > 'z') {
            message[i] = message[i] - 26;
        } else if (message[i] < 'a') {
            message[i] = message[i] + 26;
        }
    }
}

// Function to print the encrypted/decrypted message
void print(char *message) {
    printf("%s\n", message);
}

int main() {
    char message[100], encrypted[100], decrypted[100];
    int key;

    // Get message from user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get key from user
    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: ");
    print(encrypted);

    // Decrypt message
    decrypt(encrypted, key);

    // Print decrypted message
    printf("Decrypted message: ");
    print(decrypted);

    return 0;
}