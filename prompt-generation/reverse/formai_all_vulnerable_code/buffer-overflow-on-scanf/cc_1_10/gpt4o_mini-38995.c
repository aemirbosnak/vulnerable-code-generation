//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

// Act I: The Prologue
void display_prologue() {
    printf("Act I: A Darkened Room\n");
    printf("In fair Verona, where we set our scene,\n");
    printf("Two households both alike in dignity...\n\n");
    printf("In this tale of encryption and fate,\n");
    printf("We shall shift letters and characters straight.\n\n");
}

// Act II: The Encryption
void encrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char base = (text[i] >= 'a' && text[i] <= 'z') ? 'a' : 
                    (text[i] >= 'A' && text[i] <= 'Z') ? 'A' : 
                    text[i];

        if (base) {
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

// Act III: The Decryption
void decrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char base = (text[i] >= 'a' && text[i] <= 'z') ? 'a' : 
                    (text[i] >= 'A' && text[i] <= 'Z') ? 'A' : 
                    text[i];

        if (base) {
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

// Act IV: The Tragedy Unfolds
void display_tragedy() {
    printf("Act IV: The Conflict Ensues\n");
    printf("Romeo and Juliet encrypt their messages.\n");
    printf("But can love truly survive the shadows of deceit?\n");
    printf("Let us proceed: to encrypt and decrypt!\n");
}

// Act V: The Conclusion
void conclude() {
    printf("Act V: A Love Story Resolved\n");
    printf("Though encrypted, love shall find a way...\n");
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;

    // Act I: Prologue
    display_prologue();

    // Input section
    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0; // Remove the trailing newline character

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure shift is in valid range
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! It must be between 1 and 25.\n");
        return -1;
    }

    // Act II: Encrypt the text
    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    // Act III: Decrypt the text
    decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    // Act IV: Display Tragedy
    display_tragedy();

    // Act V: Conclusion
    conclude();

    return 0;
}