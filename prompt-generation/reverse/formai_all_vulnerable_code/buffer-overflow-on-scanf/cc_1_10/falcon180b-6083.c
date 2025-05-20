//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the key
#define KEY "mysecretkey"

// Define the encryption function
void encrypt(char *message) {
    int i, j;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    
    // Shift the key by the length of the message
    for (i = strlen(message); i < strlen(KEY); i++) {
        key[i] = tolower(key[i]);
    }
    
    // Encrypt the message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            message[i] = message[i] + key[i % strlen(KEY)];
        }
    }
}

// Define the decryption function
void decrypt(char *message) {
    int i, j;
    char key[strlen(KEY)];
    strcpy(key, KEY);

    // Shift the key by the length of the message
    for (i = strlen(message); i < strlen(KEY); i++) {
        key[i] = tolower(key[i]);
    }

    // Decrypt the message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            message[i] = message[i] - key[i % strlen(KEY)];
        }
    }
}

// Define the main function
int main() {
    char message[1000];
    char choice;
    int length;

    printf("Enter a message to encrypt/decrypt (maximum 1000 characters): ");
    scanf("%s", message);

    printf("Enter your choice:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf(" %c", &choice);

    switch (choice) {
        case '1':
            encrypt(message);
            printf("Encrypted message: %s\n", message);
            break;
        case '2':
            decrypt(message);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}