//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + shift) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + shift) % 26;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decryption is just a reverse shift
}

int main() {
    char text[MAX_LEN];
    int shift, choice;

    printf("Welcome to the C Encryption Program!\n");
    printf("---------------------------------------\n");
    
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left after scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // To consume the newline character left after scanf
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please use a number between 1 and 25.\n");
                    break;
                }

                encrypt(text, shift);
                printf("Encrypted message: %s\n", text);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // To consume the newline character left after scanf
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please use a number between 1 and 25.\n");
                    break;
                }
                
                decrypt(text, shift);
                printf("Decrypted message: %s\n", text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}