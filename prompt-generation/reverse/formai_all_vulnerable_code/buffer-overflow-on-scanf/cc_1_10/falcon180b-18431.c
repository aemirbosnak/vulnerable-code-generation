//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char message[], int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char message[], int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[100], key;
    int choice;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get encryption/decryption choice from user
    printf("Enter 1 for encryption or 2 for decryption: ");
    scanf("%d", &choice);

    // Get key from user
    printf("Enter key: ");
    scanf("%d", &key);

    // Perform encryption or decryption based on user choice
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}