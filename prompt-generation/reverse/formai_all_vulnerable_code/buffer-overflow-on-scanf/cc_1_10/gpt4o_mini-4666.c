//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        // Encrypt uppercase letters
        if (isupper(ch))
            text[i] = (ch + shift - 'A') % 26 + 'A';
        // Encrypt lowercase letters
        else if (islower(ch))
            text[i] = (ch + shift - 'a') % 26 + 'a';
        // Non-alphabetic characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        // Decrypt uppercase letters
        if (isupper(ch))
            text[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        // Decrypt lowercase letters
        else if (islower(ch))
            text[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        // Non-alphabetic characters remain unchanged
    }
}

int main() {
    char text[MAX_LEN];
    int shift;
    int choice;

    printf("Caesar Cipher Encryption Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // to consume newline character after the choice input

    printf("Enter the text (max %d characters): ", MAX_LEN - 1);
    fgets(text, MAX_LEN, stdin);
    
    // Remove newline character from the end of the string, if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Enter shift value (0-25): ");
    scanf("%d", &shift);
    // Ensure shift is within 0-25
    shift = shift % 26;

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid option chosen!\n");
    }

    return 0;
}