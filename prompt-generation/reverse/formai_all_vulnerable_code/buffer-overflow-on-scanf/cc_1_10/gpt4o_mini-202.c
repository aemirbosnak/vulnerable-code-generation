//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *input, int shift);
void decrypt(char *input, int shift);
void clearBuffer();

int main() {
    char input[MAX_LEN];
    int shift;
    int choice;

    printf("=== Simple Caesar Cipher ===\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    clearBuffer();

    if (choice == 1) {
        printf("Enter text to encrypt: ");
        fgets(input, MAX_LEN, stdin);
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        clearBuffer();

        encrypt(input, shift);
    } else if (choice == 2) {
        printf("Enter text to decrypt: ");
        fgets(input, MAX_LEN, stdin);
        // Remove newline character
        input[strcspn(input, "\n")] = 0;
        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        clearBuffer();

        decrypt(input, shift);
    } else {
        printf("Invalid choice! Please restart the program.\n");
    }

    return 0;
}

void encrypt(char *input, int shift) {
    char output[MAX_LEN];
    int i;
    shift = shift % 26; // Ensure shift is within 0-25

    for (i = 0; input[i] != '\0' && i < MAX_LEN; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base + shift) % 26 + base;
        } else {
            output[i] = input[i]; // Non-alphabet characters are unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the string
    printf("Encrypted text: %s\n", output);
}

void decrypt(char *input, int shift) {
    char output[MAX_LEN];
    int i;
    shift = shift % 26; // Ensure shift is within 0-25
    shift = 26 - shift; // Reverse the shift for decryption

    for (i = 0; input[i] != '\0' && i < MAX_LEN; i++) {
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base + shift) % 26 + base;
        } else {
            output[i] = input[i]; // Non-alphabet characters are unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", output);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}