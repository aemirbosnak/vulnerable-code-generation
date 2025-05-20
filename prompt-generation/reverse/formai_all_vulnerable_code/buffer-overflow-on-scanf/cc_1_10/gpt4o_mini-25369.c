//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plainText, int key, char *cipherText) {
    int i;
    for (i = 0; i < strlen(plainText); i++) {
        // Encrypt each character
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = (plainText[i] - 'A' + key) % 26 + 'A';
        } else if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = (plainText[i] - 'a' + key) % 26 + 'a';
        } else {
            cipherText[i] = plainText[i]; // Non-alphabetic characters remain unchanged
        }
    }
    cipherText[i] = '\0'; // Null-terminate the string
}

void decrypt(char *cipherText, int key, char *plainText) {
    int i;
    for (i = 0; i < strlen(cipherText); i++) {
        // Decrypt each character
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z') {
            plainText[i] = (cipherText[i] - 'A' - key + 26) % 26 + 'A'; // +26 to avoid negative
        } else if (cipherText[i] >= 'a' && cipherText[i] <= 'z') {
            plainText[i] = (cipherText[i] - 'a' - key + 26) % 26 + 'a'; // +26 to avoid negative
        } else {
            plainText[i] = cipherText[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plainText[i] = '\0'; // Null-terminate the string
}

int main() {
    char text[256];
    char cipher[256];
    char decrypted[256];
    int key;

    // Visionary welcome
    printf("Welcome to the Ethereal Encryption Portal!\n");
    printf("Where your words metamorphose into secret messages.\n");
    
    // User input
    printf("Please enter the text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline character

    printf("Enter the encryption key (number between 1 and 25): ");
    scanf("%d", &key);
    if (key < 1 || key > 25) {
        printf("Invalid key. Please rerun and select a key between 1 and 25.\n");
        return 1;
    }

    // Encrypt the input
    encrypt(text, key, cipher);
    printf("Encrypted message: %s\n", cipher);

    // Decrypt the message
    decrypt(cipher, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    // Farewell
    printf("Your words have traveled through the cosmic realm of encryption.\n");
    printf("They return unscathed, safeguarded by the secret keeper.\n");
    
    return 0;
}