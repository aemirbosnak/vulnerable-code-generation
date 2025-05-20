//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 13

void encrypt(char *message) {
    int i, len = strlen(message);
    char c;

    // simple Caesar cipher algorithm
    for (i = 0; i < len; i++) {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') + KEY) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') + KEY) % 26 + 'A';
        }
        message[i] = c;
    }
}

void decrypt(char *message) {
    int i, len = strlen(message);
    char c;

    // reverse Caesar cipher algorithm
    for (i = 0; i < len; i++) {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a') - KEY + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A') - KEY + 26) % 26 + 'A';
        }
        message[i] = c;
    }
}

int main() {
    char message[100], choice;
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter 'E' to encrypt, 'D' to decrypt: ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(message);
        printf("Encrypted message: %s", message);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(message);
        printf("Decrypted message: %s", message);
    } else {
        printf("Invalid choice.");
    }

    return 0;
}