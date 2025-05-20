//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] + key;
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void decrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] - key;
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void displayMenu() {
    printf("Welcome to the Simple Encryption Program!\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    char input[256];
    char output[256];
    int choice, key;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in the input buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove the newline character from input
                
                printf("Enter encryption key (integer): ");
                scanf("%d", &key);
                
                encrypt(input, output, key);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove the newline character from input
                
                printf("Enter decryption key (integer): ");
                scanf("%d", &key);
                
                decrypt(input, output, key);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }
    
    return 0; 
}