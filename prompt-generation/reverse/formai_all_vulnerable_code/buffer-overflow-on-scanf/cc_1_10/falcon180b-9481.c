//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a string using a Caesar cipher
void encrypt(char *message, int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = (char)(((int)message[i] - 65 + key) % 26 + 65);
        }
    }
}

// Function to decrypt a string using a Caesar cipher
void decrypt(char *message, int key) {
    int i, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = (char)(((int)message[i] - 65 - key + 26) % 26 + 65);
        }
    }
}

int main() {
    char message[1000];
    int key, choice;

    // Get the message and key from the user
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]", message);
    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    // Ask the user whether to encrypt or decrypt
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    // Encrypt or decrypt the message based on user choice
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