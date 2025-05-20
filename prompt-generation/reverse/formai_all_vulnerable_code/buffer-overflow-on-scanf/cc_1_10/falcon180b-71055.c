//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using the Caesar cipher
void encrypt(char message[], int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + key - 65);
            } else {
                message[i] = toupper(message[i] + key - 97);
            }
        }
    }
}

// Function to decrypt the message using the Caesar cipher
void decrypt(char message[], int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] - key - 65);
            } else {
                message[i] = toupper(message[i] - key - 97);
            }
        }
    }
}

int main() {
    char message[1000];
    int key, choice;

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    // Get the choice of encryption or decryption
    printf("Enter 1 for encryption and 2 for decryption: ");
    scanf("%d", &choice);

    // Encrypt or decrypt the message based on the user's choice
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}