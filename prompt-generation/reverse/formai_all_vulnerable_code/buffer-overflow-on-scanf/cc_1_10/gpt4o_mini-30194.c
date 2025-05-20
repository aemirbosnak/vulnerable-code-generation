//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int shift) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            message[i] = (ch + shift - 'a') % 26 + 'a';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int shift) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            message[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        }
    }
}

// Function to print the menu
void printMenu() {
    printf("----- Caesar Cipher -----\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char message[256];
    int shift, choice;

    while(1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter your message: ");
        getchar(); // To consume the newline left by scanf
        fgets(message, sizeof(message), stdin);
        
        // Remove trailing newline character from fgets
        message[strcspn(message, "\n")] = 0;
        
        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        
        // Ensure the shift is within correct bounds
        if(shift < 1 || shift > 25) {
            printf("Invalid shift value! Please enter a shift value between 1 and 25.\n");
            continue;
        }

        if(choice == 1) {
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
        } else if(choice == 2) {
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}