//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 21 // Change the key according to your preference (1-26)

void encrypt(char *message) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + KEY;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + KEY;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char *message) {
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - KEY;

            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - KEY;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("\n1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message);
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }

    return 0;
}