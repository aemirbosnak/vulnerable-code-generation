//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void shiftCharacters(char *text, int shift);
void displayMenu();
void clearBuffer();

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift, choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        clearBuffer(); // Clear input buffer to avoid reading issues

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter shift amount: ");
                scanf("%d", &shift);
                encrypt(text, shift);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter shift amount: ");
                scanf("%d", &shift);
                decrypt(text, shift);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    return 0;
}

void encrypt(char *text, int shift) {
    printf("Encrypted Text: ");
    shiftCharacters(text, shift);
}

void decrypt(char *text, int shift) {
    printf("Decrypted Text: ");
    shiftCharacters(text, -shift);
}

void shiftCharacters(char *text, int shift) {
    char *ptr = text;
    while (*ptr) {
        if (isalpha(*ptr)) {
            char base = islower(*ptr) ? 'a' : 'A';
            *ptr = (char)(((*ptr - base + shift + 26) % 26) + base);
        }
        putchar(*ptr);
        ptr++;
    }
    putchar('\n');
}

void displayMenu() {
    printf("\nCaesar Cipher Encryption/Decryption\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}