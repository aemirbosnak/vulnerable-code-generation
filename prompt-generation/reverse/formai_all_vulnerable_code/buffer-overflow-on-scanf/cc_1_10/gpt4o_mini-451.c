//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to encrypt the text using Caesar cipher
void encrypt(char* plainText, char* cipherText, int shift) {
    for (int i = 0; plainText[i] != '\0'; ++i) {
        char ch = plainText[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            cipherText[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            cipherText[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // If it's not a letter, keep it as is
        else {
            cipherText[i] = ch;
        }
    }
    cipherText[strlen(plainText)] = '\0'; // Null terminate the string
}

// Function to decrypt the text using Caesar cipher
void decrypt(char* cipherText, char* plainText, int shift) {
    for (int i = 0; cipherText[i] != '\0'; ++i) {
        char ch = cipherText[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plainText[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // +26 to handle negative shifts
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plainText[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // +26 to handle negative shifts
        }
        // If it's not a letter, keep it as is
        else {
            plainText[i] = ch;
        }
    }
    plainText[strlen(cipherText)] = '\0'; // Null terminate the string
}

int main() {
    char plainText[MAX_LEN];
    char cipherText[MAX_LEN];
    char decryptedText[MAX_LEN];
    int shift;

    printf("Enter the text to encrypt (max 100 characters): ");
    fgets(plainText, MAX_LEN, stdin);
    plainText[strcspn(plainText, "\n")] = 0; // Remove newline character

    // Get the shift value from user
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please run the program again with a valid shift (1-25).\n");
        return 1;
    }

    // Encrypt the plain text
    encrypt(plainText, cipherText, shift);
    printf("Encrypted Text: %s\n", cipherText);

    // Decrypt the cipher text
    decrypt(cipherText, decryptedText, shift);
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}