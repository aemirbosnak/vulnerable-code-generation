//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message using Caesar cipher
void encrypt(char message[], int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char message[], int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - key - 65) % 26 + 65;
            } else {
                message[i] = (message[i] - key - 97) % 26 + 97;
            }
        }
    }
}

int main() {
    char message[1000], choice;
    int key, n, i;

    // Get message from user
    printf("Enter message to be encrypted/decrypted: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from message
    n = strlen(message);
    message[n - 1] = '\0';

    // Get encryption/decryption choice from user
    printf("Enter 'e' for encryption or 'd' for decryption: ");
    scanf("%c", &choice);

    // Get key from user
    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt/decrypt message based on user choice
    if (choice == 'e' || choice == 'E') {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}