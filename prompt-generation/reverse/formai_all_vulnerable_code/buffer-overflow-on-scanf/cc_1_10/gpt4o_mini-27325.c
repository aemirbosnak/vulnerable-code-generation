//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
char *getInput();
void freeMemory(char *ptr);

int main() {
    int choice, shift;
    char *inputText = NULL;

    printf("Simple Caesar Cipher Encryption Tool\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);
    
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Must be between 1 and 25.\n");
        return 1;
    }

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter the text: ");
    inputText = getInput();

    if (choice == 1) {
        printf("Encrypted text: ");
        encrypt(inputText, shift);
    } else if (choice == 2) {
        printf("Decrypted text: ");
        decrypt(inputText, shift);
    } else {
        printf("Invalid choice.\n");
    }

    // Clean up
    freeMemory(inputText);
    return 0;
}

void encrypt(char *text, int shift) {
    int i;
    char ch;
    int textLength = strlen(text);
    
    for (i = 0; i < textLength; i++) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        printf("%c", ch);
    }
    printf("\n");
}

void decrypt(char *text, int shift) {
    int i;
    char ch;
    int textLength = strlen(text);

    for (i = 0; i < textLength; i++) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift - 'a' + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        printf("%c", ch);
    }
    printf("\n");
}

char *getInput() {
    size_t bufferSize = 1024;
    char *buffer = (char *)malloc(bufferSize);
    
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    if (fgets(buffer, bufferSize, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        freeMemory(buffer);
        exit(1);
    }

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = 0;

    return buffer;
}

void freeMemory(char *ptr) {
    if (ptr) {
        free(ptr);
    }
}