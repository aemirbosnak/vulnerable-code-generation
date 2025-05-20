//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void encrypt(const char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            output[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            output[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the string
}

void decrypt(const char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Decrypt uppercase letters
        if (isupper(ch)) {
            output[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(ch)) {
            output[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the string
}

int main() {
    char input[MAX_LENGTH];
    char encrypted[MAX_LENGTH];
    char decrypted[MAX_LENGTH];
    int shift;

    printf("Enter a string to encrypt (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character

    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure the shift is within the range
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please enter a value between 1 and 25.\n");
        return 1;
    }

    encrypt(input, encrypted, shift);
    decrypt(encrypted, decrypted, shift);

    printf("Original String: %s\n", input);
    printf("Encrypted String: %s\n", encrypted);
    printf("Decrypted String: %s\n", decrypted);

    return 0;
}