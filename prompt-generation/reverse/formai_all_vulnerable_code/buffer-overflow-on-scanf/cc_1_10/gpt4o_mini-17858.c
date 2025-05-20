//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define SHIFT 3

// Function declarations
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void transform_string(char *text);
void display_menu();

// Main function
int main() {
    char buffer[BUFFER_SIZE];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                encrypt(buffer, SHIFT);
                printf("Encrypted Text: %s\n", buffer);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                decrypt(buffer, SHIFT);
                printf("Decrypted Text: %s\n", buffer);
                break;
            case 3:
                printf("Enter text to transform: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                transform_string(buffer);
                printf("Transformed Text: %s\n", buffer);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char base = islower(text[i]) ? 'a' : 'A';
        if (isalpha(text[i])) {
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char base = islower(text[i]) ? 'a' : 'A';
        if (isalpha(text[i])) {
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

void transform_string(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = islower(text[i]) ? toupper(text[i]) : tolower(text[i]);
        }
    }
}

void display_menu() {
    printf("\n*** String Manipulation Menu ***\n");
    printf("1. Encrypt a string\n");
    printf("2. Decrypt a string\n");
    printf("3. Transform string case\n");
    printf("4. Exit\n");
}