//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum message size
#define KEY 3 // encryption key

void encrypt(char message[], int key) {

    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++) {

        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("\nEncrypted Message: %s\n", message);
}

void decrypt(char message[], int key) {

    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++) {

        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }

        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }

    printf("\nDecrypted Message: %s\n", message);
}

int main() {

    char message[MAX_SIZE];
    int choice;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0;

    printf("\nChoose from the following options:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            encrypt(message, KEY);
            break;

        case 2:
            decrypt(message, KEY);
            break;

        default:
            printf("\nInvalid Choice\n");
    }

    return 0;
}