//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        // Encrypt uppercase letters
        if (isupper(input[i])) {
            output[i] = (input[i] - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(input[i])) {
            output[i] = (input[i] - 'a' + key) % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            output[i] = input[i];
        }
    }
    output[len] = '\0'; // Null terminate the output string
}

void decrypt(char *input, char *output, int key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        // Decrypt uppercase letters
        if (isupper(input[i])) {
            output[i] = (input[i] - 'A' - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(input[i])) {
            output[i] = (input[i] - 'a' - key + 26) % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            output[i] = input[i];
        }
    }
    output[len] = '\0'; // Null terminate the output string
}

void displayMenu() {
    printf("\n--- Caesar Cipher Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char input[256];
    char output[256];
    int choice, key;
    
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                scanf(" %[^\n]", input); // Read a line with spaces
                printf("Enter a key (1-25): ");
                scanf("%d", &key);
                
                // Validate the key
                if (key < 1 || key > 25) {
                    printf("Invalid key! Please choose a key between 1 and 25.\n");
                    break;
                }
                
                encrypt(input, output, key);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter a message to decrypt: ");
                scanf(" %[^\n]", input);
                printf("Enter the key used for encryption (1-25): ");
                scanf("%d", &key);
                
                // Validate the key
                if (key < 1 || key > 25) {
                    printf("Invalid key! Please choose a key between 1 and 25.\n");
                    break;
                }
                
                decrypt(input, output, key);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}