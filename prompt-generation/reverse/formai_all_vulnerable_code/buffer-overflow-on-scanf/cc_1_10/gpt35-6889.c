//FormAI DATASET v1.0 Category: modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function encrypts the message using a Caesar cipher algorithm */
void caesar_cipher_encrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        /* Encrypt uppercase letters */
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }
        /* Encrypt lowercase letters */
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
    }
}

/* This function decrypts the message using a Caesar cipher algorithm */
void caesar_cipher_decrypt(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        /* Decrypt uppercase letters */
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A') - shift + 26) % 26 + 'A';
        }
        /* Decrypt lowercase letters */
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') - shift + 26) % 26 + 'a';
        }
    }
}

/* This is a driver function */
int main() {
    int choice, shift;
    char message[1000];
    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0; /* Remove the newline character from the input */
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    printf("Enter 1 to encrypt the message or enter 2 to decrypt the message: ");
    scanf("%d", &choice);
    if (choice == 1) {
        caesar_cipher_encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    }
    else if (choice == 2) {
        caesar_cipher_decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    }
    else {
        printf("Invalid choice. Please enter 1 to encrypt or 2 to decrypt.\n");
        return 1;
    }
    return 0;
}