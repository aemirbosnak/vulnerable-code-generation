//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void displayMenu();

int main() {
    char text[1024];
    int shift;
    int choice;

    printf("🌟 Welcome to the Happy Caesar Cipher Program! 🌟\n");

    while (1) {
        displayMenu();
        
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("😊 You chose to Encrypt a message!\n");
                printf("Enter the message to encrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter your shift value (1-25): ");
                scanf("%d", &shift);
                encrypt(text, shift);
                break;

            case 2:
                printf("😄 You chose to Decrypt a message!\n");
                printf("Enter the message to decrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter your shift value (1-25): ");
                scanf("%d", &shift);
                decrypt(text, shift);
                break;

            case 3:
                printf("🎉 Exiting the Happy Cipher Program! Goodbye! 🎉\n");
                exit(0);

            default:
                printf("😅 Oops! Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void displayMenu() {
    printf("---------------\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("---------------\n");
}

void encrypt(char *text, int shift) {
    char ch;
    printf("Encrypted message: ");
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        putchar(ch);
    }
    printf("\n");
}

void decrypt(char *text, int shift) {
    char ch;
    printf("Decrypted message: ");
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26 + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26 + 26) % 26 + 'A';
        }
        putchar(ch);
    }
    printf("\n");
}