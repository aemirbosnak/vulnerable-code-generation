//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define KEY 5  // Shift key for the Caesar cipher

void encrypt(char *plaintext, char *ciphertext) {
    int i, len = strlen(plaintext);
    
    for (i = 0; i < len; i++) {
        // Encrypt only letters
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + KEY) % 26 + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + KEY) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[len] = '\0';  // Null-terminate the string
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, len = strlen(ciphertext);
    
    for (i = 0; i < len; i++) {
        // Decrypt only letters
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - KEY + 26) % 26 + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - KEY + 26) % 26 + 'A';
        } else {
            plaintext[i] = ciphertext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[len] = '\0';  // Null-terminate the string
}

void printMenu() {
    printf("Caesar Cipher Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];
    int option;

    while (1) {
        printMenu();
        scanf("%d", &option);
        getchar();  // Clear newline character from input buffer

        switch (option) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(plaintext, MAX_LEN, stdin);
                plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove newline character
                encrypt(plaintext, ciphertext);
                printf("Encrypted Message: %s\n", ciphertext);
                break;
            case 2:
                printf("Enter the message to decrypt: ");
                fgets(ciphertext, MAX_LEN, stdin);
                ciphertext[strcspn(ciphertext, "\n")] = '\0';  // Remove newline character
                decrypt(ciphertext, decryptedtext);
                printf("Decrypted Message: %s\n", decryptedtext);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}