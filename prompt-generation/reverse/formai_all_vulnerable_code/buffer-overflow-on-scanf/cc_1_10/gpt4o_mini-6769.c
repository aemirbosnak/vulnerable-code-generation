//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

void encrypt(char* text, int shift);
void decrypt(char* text, int shift);
static int get_integer_input(const char* prompt);

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    
    // Get plaintext from the user
    printf("Enter text to encrypt (max %d characters): ", MAX_TEXT_LENGTH - 1);
    fgets(text, sizeof(text), stdin);
    // Remove the newline character if present
    text[strcspn(text, "\n")] = 0; 

    shift = get_integer_input("Enter shift value (1-25): ");

    // Encrypt the text
    encrypt(text, shift);
    
    // Get user confirmation for decryption
    char confirm;
    printf("Would you like to decrypt the text? (y/n): ");
    scanf(" %c", &confirm);
    
    if (tolower(confirm) == 'y') {
        decrypt(text, shift);
    }

    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}

void encrypt(char* text, int shift) {
    char encrypted[MAX_TEXT_LENGTH];
    int len = strlen(text);
    
    for (int i = 0; i < len; i++) {
        char c = text[i];

        // Encrypt uppercase letters
        if (isupper(c)) {
            encrypted[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(c)) {
            encrypted[i] = (c + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            encrypted[i] = c;
        }
    }
    encrypted[len] = '\0'; // Null-terminate the string
    printf("Encrypted text: %s\n", encrypted);
}

void decrypt(char* text, int shift) {
    char decrypted[MAX_TEXT_LENGTH];
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        char c = text[i];

        // Decrypt uppercase letters
        if (isupper(c)) {
            decrypted[i] = (c - shift - 'A' + 26) % 26 + 'A'; // +26 to ensure positive index
        }
        // Decrypt lowercase letters
        else if (islower(c)) {
            decrypted[i] = (c - shift - 'a' + 26) % 26 + 'a'; // +26 to ensure positive index
        }
        // Non-alphabetic characters remain unchanged
        else {
            decrypted[i] = c;
        }
    }
    decrypted[len] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", decrypted);
}

static int get_integer_input(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        scanf("%d", &value);
        if (value >= 1 && value <= 25) {
            return value;
        } else {
            printf("Invalid input. Please enter a number between 1 and 25.\n");
        }
    }
}