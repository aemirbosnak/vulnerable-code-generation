//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define the key
#define KEY "mysecretkey"

// Define the encryption function
void encrypt(char *message, int key_length) {
    int i, j;
    char key[key_length];
    strcpy(key, KEY);

    // Generate a random string of characters to use as the encryption key
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }

    // Encrypt the message using the key
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]) - 'A' + key[i % key_length] - 'a';
        }
    }
}

// Define the decryption function
void decrypt(char *message, int key_length) {
    int i, j;
    char key[key_length];
    strcpy(key, KEY);

    // Generate the same encryption key used in the encryption function
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }

    // Decrypt the message using the key
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]) - 'A' - key[i % key_length] + 'a';
        }
    }
}

int main() {
    char message[100];
    int choice, key_length;

    // Get the message from the user
    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the encryption/decryption choice from the user
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    // Get the key length from the user
    printf("Enter the key length (between 1 and %d): ", strlen(KEY));
    scanf("%d", &key_length);

    // Encrypt/decrypt the message
    if (choice == 1) {
        encrypt(message, key_length);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, key_length);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}