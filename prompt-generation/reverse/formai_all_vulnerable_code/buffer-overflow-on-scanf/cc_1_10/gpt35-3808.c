//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
/*
*  ARTISTIC CRYPTOGRAPHY IMPLEMENTATION EXAMPLE
*
*  This program encrypts and decrypts a message using the Caesar Cipher technique. The user can choose the encryption key.
*  As an artistic touch, the program outputs an ASCII art of a lock when the message is encrypted and an ASCII art of an open lock when the message is decrypted.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using the Caesar Cipher technique
void encrypt(char* message, int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 'a') % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 'A') % 26 + 'A';
        }

        message[i] = ch;
    }

    // ASCII art of locked padlock
    printf("\n\t_________________________");
    printf("\n\t|                        |");
    printf("\n\t|      ____________      |");
    printf("\n\t|    //            \\\\    |");
    printf("\n\t|   //              \\\\   |");
    printf("\n\t|  //     LOCKED     \\\\  |");
    printf("\n\t| //                  \\\\ |");
    printf("\n\t|//____________________\\\\|");
    printf("\n\t|________________________|\n\n");
}

// Function to decrypt the message using the Caesar Cipher technique
void decrypt(char* message, int key) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - key - 'a') + 26) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - key - 'A') + 26) % 26 + 'A';
        }

        message[i] = ch;
    }

    // ASCII art of unlocked padlock
    printf("\n\t_________________________");
    printf("\n\t|                        |");
    printf("\n\t|      ____________      |");
    printf("\n\t|    //            \\\\    |");
    printf("\n\t|   //              \\\\   |");
    printf("\n\t|  //     UNLOCKED   \\\\  |");
    printf("\n\t| //                  \\\\ |");
    printf("\n\t|//____________________\\\\|");
    printf("\n\t|________________________|\n\n");
}

int main() {
    char message[1000];
    int key, choice;

    printf("Enter message: ");
    fgets(message, 1000, stdin);
    strtok(message, "\n"); // remove trailing newline

    printf("Enter encryption key: ");
    scanf("%d", &key);

    // menu for user to choose encryption or decryption
    printf("What do you want to do?\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
        break;
    case 2:
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
        break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}