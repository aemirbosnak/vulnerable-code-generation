//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void print_banner() {
    printf("***************************************\n");
    printf("*            Retro Crypt              *\n");
    printf("*          Simple Encryption          *\n");
    printf("***************************************\n");
}

void caesar_encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            output[i] = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            output[i] = ((ch - 'A' + shift) % 26) + 'A';
        } else {
            output[i] = ch; // Non-alphabetic characters are unchanged
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void caesar_decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            output[i] = ((ch - 'a' - shift + 26) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            output[i] = ((ch - 'A' - shift + 26) % 26) + 'A';
        } else {
            output[i] = ch; // Non-alphabetic characters are unchanged
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

int main() {
    print_banner();

    char input[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int shift;

    printf("Enter the text to encrypt (max %d characters): ", MAX_LEN - 1);
    fgets(input, MAX_LEN, stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);
    
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please enter a number between 1 and 25.\n");
        return 1;
    }

    caesar_encrypt(input, shift, encrypted);
    printf("Encrypted: %s\n", encrypted);

    caesar_decrypt(encrypted, shift, decrypted);
    printf("Decrypted: %s\n", decrypted);

    // Display additional information
    printf("Thank you for using Retro Crypt!\n");
    printf("Remember to keep your shift value secret for maximum security.\n");

    return 0;
}