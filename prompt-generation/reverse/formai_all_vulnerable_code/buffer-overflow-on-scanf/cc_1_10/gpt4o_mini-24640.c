//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024
#define SHIFT_KEY 4

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char current = text[i];
        if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' + shift) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' + shift) % 26 + 'A';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char current = text[i];
        if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' - shift + 26) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

void printMenu() {
    printf("===========================================\n");
    printf("           Simple C Encryption            \n");
    printf("===========================================\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("===========================================\n");
    printf("Please choose an option: ");
}

void handleOption(int option) {
    char text[MAX_TEXT_SIZE];

    switch (option) {
        case 1:
            printf("Enter text to encrypt: ");
            getchar();  // Clear the newline from previous input
            fgets(text, MAX_TEXT_SIZE, stdin);
            text[strcspn(text, "\n")] = '\0';  // Remove newline character
            encrypt(text, SHIFT_KEY);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            printf("Enter text to decrypt: ");
            getchar();  // Clear the newline from previous input
            fgets(text, MAX_TEXT_SIZE, stdin);
            text[strcspn(text, "\n")] = '\0';  // Remove newline character
            decrypt(text, SHIFT_KEY);
            printf("Decrypted text: %s\n", text);
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}

int main() {
    int option;

    while (1) {
        printMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }
        handleOption(option);
    }

    return 0;
}