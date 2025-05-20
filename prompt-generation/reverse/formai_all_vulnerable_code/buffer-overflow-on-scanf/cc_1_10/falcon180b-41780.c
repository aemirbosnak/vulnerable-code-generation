//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26
#define KEY 5

// Function to encrypt message using Caesar cipher
void encrypt(char *message) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + KEY) % SIZE + 'A';
            } else {
                message[i] = (message[i] - 'a' + KEY) % SIZE + 'a';
            }
        }
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char *message) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - KEY + SIZE) % SIZE + 'A';
            } else {
                message[i] = (message[i] - 'a' - KEY + SIZE) % SIZE + 'a';
            }
        }
    }
}

// Function to remove all non-alphabetic characters from string
void remove_non_alpha(char *message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[j++] = message[i];
        }
    }
    message[j] = '\0';
}

int main() {
    char message[1000];
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    remove_non_alpha(message);

    int choice;
    printf("\nChoose an option:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}