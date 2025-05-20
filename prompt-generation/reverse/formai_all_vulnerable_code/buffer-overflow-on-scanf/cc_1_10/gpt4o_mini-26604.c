//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define ENCRYPTION_KEY 5

void encrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + ENCRYPTION_KEY;
    }
    output[i] = '\0'; // null-terminate the output string
}

void decrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] - ENCRYPTION_KEY;
    }
    output[i] = '\0'; // null-terminate the output string
}

void displayMenu() {
    printf("Simple C Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int choice;
    
    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid option! Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                // Clear newline left by scanf
                getchar();
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                
                encrypt(input, output);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                // Clear newline left by scanf
                getchar();
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                
                decrypt(input, output);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}