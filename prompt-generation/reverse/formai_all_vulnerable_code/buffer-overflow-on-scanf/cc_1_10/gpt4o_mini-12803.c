//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu() {
    printf("=========================================\n");
    printf("!!! Welcome to the Shocking Encryption !!!\n");
    printf("=========================================\n");
    printf("1: Encrypt a Message\n");
    printf("2: Decrypt a Message\n");
    printf("3: Exit\n");
    printf("=========================================\n");
    printf("Choose an option (1-3): ");
}

void encrypt_message(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + shift) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        }
    }
}

void decrypt_message(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - shift + 26) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - shift + 26) % 26) + 'A';
        }
    }
}

int main() {
    char message[256];
    int shift = 0;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // to consume the newline character
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character

                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift! Please choose a number between 1 and 25.\n");
                    break;
                }
                
                encrypt_message(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // to consume the newline character
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character

                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift! Please choose a number between 1 and 25.\n");
                    break;
                }
                
                decrypt_message(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}