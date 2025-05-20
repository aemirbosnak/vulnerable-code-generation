//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(char *input, char *output, char key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] ^ key; // XOR operation
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void displayMenu() {
    printf("************************************\n");
    printf("         Modern Encryption          \n");
    printf("************************************\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("************************************\n");
    printf("Choose an option: ");
}

int main() {
    char input[256];
    char output[256];
    char key;
    int choice;

    printf("Welcome to the Retro Encryption Program\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                scanf(" %255[^\n]", input); // Read string with spaces
                printf("Enter encryption key (single character): ");
                scanf(" %c", &key);
                encryptDecrypt(input, output, key);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                scanf(" %255[^\n]", input); // Read string with spaces
                printf("Enter decryption key (single character): ");
                scanf(" %c", &key);
                encryptDecrypt(input, output, key);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\n");
    }
    
    return 0;
}