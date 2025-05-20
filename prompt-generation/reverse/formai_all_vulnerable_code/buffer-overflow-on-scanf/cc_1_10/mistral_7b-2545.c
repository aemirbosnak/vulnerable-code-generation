//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 3
#define MAX_MESSAGE_LENGTH 100

void encrypt(char *message, int key) {
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (islower(c))
                c = (char)(((int)c + key - 97) % 26 + 97);
            else
                c = (char)(((int)c + key - 65) % 26 + 65);
            message[i] = c;
        }
    }
}

void decrypt(char *message, int key) {
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (islower(c))
                c = (char)(((int)c - key + 26) % 26 + 97);
            else
                c = (char)(((int)c - key + 26) % 26 + 65);
            message[i] = c;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char choice;
    int key = 3;

    printf("Welcome to the Caesar Cipher Encryption/Decryption Program!\n");
    printf("Enter the message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Do you want to encrypt(E) or decrypt(D) the message? ");
    scanf("%c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'D' || choice == 'd') {
        encrypt(message, -key); // Negative key for decryption
        printf("Decrypted message: %s\n", message);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    return 0;
}