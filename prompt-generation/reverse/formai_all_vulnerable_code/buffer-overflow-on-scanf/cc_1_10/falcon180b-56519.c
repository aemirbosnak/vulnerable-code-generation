//Falcon-180B DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 11

// Function to encrypt the message using Caesar cipher
void encrypt(char *message) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) ((int) message[i] + (int) KEY[i % KEY_LENGTH] - 97);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) ((int) message[i] + (int) KEY[i % KEY_LENGTH] - 65);
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message) {
    int i;
    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (char) ((int) message[i] - (int) KEY[i % KEY_LENGTH] + 97);
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (char) ((int) message[i] - (int) KEY[i % KEY_LENGTH] + 65);
        }
    }
}

int main() {
    char message[100];
    char choice;
    int i;

    // Get the message from the user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);

    // Get the user's choice to encrypt or decrypt
    printf("Enter E to encrypt or D to decrypt: ");
    scanf(" %c", &choice);

    // Encrypt or decrypt the message based on user's choice
    if (choice == 'E' || choice == 'e') {
        encrypt(message);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(message);
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice. Please enter E or D.\n");
    }

    return 0;
}