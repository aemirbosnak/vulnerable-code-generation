//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *input, int shift, char *output) {
    int i;
    char ch;

    for (i = 0; input[i] != '\0'; i++) {
        ch = input[i];

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
    output[i] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, int shift, char *output) {
    int i;
    char ch;

    for (i = 0; input[i] != '\0'; i++) {
        ch = input[i];

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
    output[i] = '\0'; // Null-terminate the output string
}

int main() {
    char input[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    printf("Enter shift value (0 - 25): ");
    scanf("%d", &shift);
    
    // Normalize the shift to a value between 0 and 25
    shift = shift % 26;

    encrypt(input, shift, encrypted);
    printf("Encrypted String: %s\n", encrypted);

    decrypt(encrypted, shift, decrypted);
    printf("Decrypted String: %s\n", decrypted);

    return 0;
}