//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] + key; // Simple Caesar Cipher
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void decrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] - key; // Simple Caesar Cipher
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void menu() {
    printf("\n--- Encryption Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("--------------------------\n");
}

int main() {
    char input[MAX_LEN], encrypted[MAX_LEN], decrypted[MAX_LEN];
    int choice, key;

    printf("Welcome to the Encryption Program!\n");
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the key (1-25): ");
        scanf("%d", &key);
        
        if (key < 1 || key > 25) {
            printf("Invalid key! Please enter a key between 1 and 25.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // consume the newline
                fgets(input, MAX_LEN, stdin);
                
                // Remove newline character from input string
                input[strcspn(input, "\n")] = 0;

                encrypt(input, encrypted, key);
                printf("Encrypted message: %s\n", encrypted);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // consume the newline
                fgets(input, MAX_LEN, stdin);
                
                // Remove newline character from input string
                input[strcspn(input, "\n")] = 0;

                decrypt(input, decrypted, key);
                printf("Decrypted message: %s\n", decrypted);
                break;

            default:
                printf("Invalid choice! Please select an option from the menu.\n");
                break;
        }
    }

    return 0;
}