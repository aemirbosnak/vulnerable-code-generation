//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt the given string using Caesar cipher
void encrypt(char* str, int key) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (char) (((int) str[i] - 65 + key) % 26 + 65);
            } else {
                str[i] = (char) (((int) str[i] - 97 + key) % 26 + 97);
            }
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char* str, int key) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                str[i] = (char) (((int) str[i] - 65 - key + 26) % 26 + 65);
            } else {
                str[i] = (char) (((int) str[i] - 97 - key + 26) % 26 + 97);
            }
        }
    }
}

int main() {
    char message[100];
    int key, choice;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    // Get the choice to encrypt or decrypt
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    // Encrypt or decrypt the message based on the user's choice
    if (choice == 1) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}