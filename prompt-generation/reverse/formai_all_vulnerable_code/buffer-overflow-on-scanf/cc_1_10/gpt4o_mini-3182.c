//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, int shift, char *ciphertext) {
    while (*plaintext) {
        if (*plaintext >= 'a' && *plaintext <= 'z') {
            *ciphertext = ((*plaintext - 'a' + shift) % 26) + 'a';
        } else if (*plaintext >= 'A' && *plaintext <= 'Z') {
            *ciphertext = ((*plaintext - 'A' + shift) % 26) + 'A';
        } else {
            *ciphertext = *plaintext; // Non-alphabetic characters remain unchanged
        }
        plaintext++;
        ciphertext++;
    }
    *ciphertext = '\0'; // Null terminate the string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    while (*ciphertext) {
        if (*ciphertext >= 'a' && *ciphertext <= 'z') {
            *plaintext = ((*ciphertext - 'a' - shift + 26) % 26) + 'a';
        } else if (*ciphertext >= 'A' && *ciphertext <= 'Z') {
            *plaintext = ((*ciphertext - 'A' - shift + 26) % 26) + 'A';
        } else {
            *plaintext = *ciphertext; // Non-alphabetic characters remain unchanged
        }
        ciphertext++;
        plaintext++;
    }
    *plaintext = '\0'; // Null terminate the string
}

int main() {
    int shift;
    char mode[10];
    char input[256], output[256];

    printf("Welcome to Caesar Cipher Encryption/Decryption!\n");
    printf("Please enter the shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    printf("Would you like to 'encrypt' or 'decrypt' a message? ");
    scanf("%s", mode);

    if (strcmp(mode, "encrypt") == 0) {
        printf("Enter the plaintext: ");
        getchar(); // Consume newline character left by scanf
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        encrypt(input, shift, output);
        printf("Encrypted message: %s\n", output);
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Enter the ciphertext: ");
        getchar(); // Consume newline character left by scanf
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        decrypt(input, shift, output);
        printf("Decrypted message: %s\n", output);
    } else {
        printf("Invalid mode. Please choose 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    printf("Thank you for using the Caesar Cipher program!\n");
    return 0;
}