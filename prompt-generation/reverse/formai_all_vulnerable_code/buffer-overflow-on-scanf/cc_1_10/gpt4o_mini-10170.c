//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

void encryptMessage(char *message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

void decryptMessage(char *message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base - key + 26) % 26 + base;
        }
    }
}

void displayOptions() {
    printf("\n===================\n");
    printf("   C Encryption   \n");
    printf("===================\n");
    printf("1. Encrypt Message\n");
    printf("2. Decrypt Message\n");
    printf("3. Exit\n");
    printf("===================\n");
}

int main() {
    char message[MAX_SIZE];
    int option, key;

    printf("Welcome to the Retro C Encryption Program!\n");

    while (1) {
        displayOptions();
        printf("Choose an option (1-3): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // clear newline from buffer
                fgets(message, MAX_SIZE, stdin);
                message[strcspn(message, "\n")] = 0; // remove newline

                printf("Enter the encryption key (1-25): ");
                scanf("%d", &key);

                if (key < 1 || key > 25) {
                    printf("Invalid key! Please enter a key between 1 and 25.\n");
                    break;
                }

                encryptMessage(message, key);
                printf("Encrypted Message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // clear newline from buffer
                fgets(message, MAX_SIZE, stdin);
                message[strcspn(message, "\n")] = 0; // remove newline

                printf("Enter the decryption key (1-25): ");
                scanf("%d", &key);

                if (key < 1 || key > 25) {
                    printf("Invalid key! Please enter a key between 1 and 25.\n");
                    break;
                }

                decryptMessage(message, key);
                printf("Decrypted Message: %s\n", message);
                break;

            case 3:
                printf("Thank you for using the Retro C Encryption Program!\n");
                exit(0);

            default:
                printf("Invalid option! Please choose a valid option between 1 and 3.\n");
                break;
        }
    }
    return 0;
}