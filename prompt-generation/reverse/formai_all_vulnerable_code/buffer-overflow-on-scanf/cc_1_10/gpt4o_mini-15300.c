//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key) % 26 + 'a';
        }

        message[i] = ch;
    }
}

void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - key + 26) % 26 + 'A'; // Adding 26 to ensure positive
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        }

        message[i] = ch;
    }
}

int main() {
    char message[MAX_LEN];
    int key;
    int option;

    printf("\nWelcome to Caesar Cipher Cryptography Program!");
    printf("\n==============================================");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 3) {
            break; // Exit the program
        }

        printf("Enter your message: ");
        // Clear the input buffer before reading string
        getchar(); // Consume the newline from previous input
        fgets(message, MAX_LEN, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        printf("Enter key (1-25): ");
        scanf("%d", &key);
        key = key % 26; // Ensure key is within the range

        if (option == 1) {
            encrypt(message, key);
            printf("Encrypted Message: %s\n", message);
        } else if (option == 2) {
            decrypt(message, key);
            printf("Decrypted Message: %s\n", message);
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    printf("Thank you for using the program! Goodbye.\n");
    return 0;
}