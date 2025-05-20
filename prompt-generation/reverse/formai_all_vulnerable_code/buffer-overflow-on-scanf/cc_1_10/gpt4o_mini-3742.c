//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(const char *plain, char *cipher, int shift);
void decrypt(const char *cipher, char *plain, int shift);
void print_menu();

int main() {
    int choice, shift;
    char input[MAX_LEN], output[MAX_LEN];

    print_menu();
    scanf("%d", &choice);
    getchar(); // to consume newline after integer input

    if (choice == 1 || choice == 2) {
        printf("Enter your text: ");
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline

        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);

        if (shift < 1 || shift > 25) {
            printf("Invalid shift value! Please enter a value between 1 and 25.\n");
            return 1;
        }

        if (choice == 1) {
            encrypt(input, output, shift);
            printf("Encrypted text: %s\n", output);
        } else {
            decrypt(input, output, shift);
            printf("Decrypted text: %s\n", output);
        }
    } else {
        printf("Invalid choice! Exiting.\n");
    }

    return 0;
}

void encrypt(const char *plain, char *cipher, int shift) {
    for (int i = 0; plain[i] != '\0'; i++) {
        if (plain[i] >= 'a' && plain[i] <= 'z') {
            cipher[i] = ((plain[i] - 'a' + shift) % 26) + 'a';
        } else if (plain[i] >= 'A' && plain[i] <= 'Z') {
            cipher[i] = ((plain[i] - 'A' + shift) % 26) + 'A';
        } else {
            cipher[i] = plain[i]; // Non-alphabetic characters remain unchanged
        }
    }
    cipher[strlen(plain)] = '\0'; // Null-terminate the cipher string
}

void decrypt(const char *cipher, char *plain, int shift) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'a' && cipher[i] <= 'z') {
            plain[i] = ((cipher[i] - 'a' - shift + 26) % 26) + 'a';
        } else if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            plain[i] = ((cipher[i] - 'A' - shift + 26) % 26) + 'A';
        } else {
            plain[i] = cipher[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plain[strlen(cipher)] = '\0'; // Null-terminate the plain string
}

void print_menu() {
    printf("Welcome to Simple Caesar Cipher\n");
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
}