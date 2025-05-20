//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEXT_SIZE 128
#define ALPHABET_SIZE 26

void encrypt_caesar(const char *plaintext, char *ciphertext, int shift);
void decrypt_caesar(const char *ciphertext, char *plaintext, int shift);
void display_menu();
int get_shift_value();

int main() {
    char plaintext[MAX_TEXT_SIZE];
    char ciphertext[MAX_TEXT_SIZE];
    int choice, shift;

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        if (choice == 1) {
            printf("Enter plaintext (max %d characters): ", MAX_TEXT_SIZE - 1);
            fgets(plaintext, MAX_TEXT_SIZE, stdin);
            plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline
            
            shift = get_shift_value();
            encrypt_caesar(plaintext, ciphertext, shift);
            printf("Encrypted text: %s\n", ciphertext);
        } else if (choice == 2) {
            printf("Enter ciphertext (max %d characters): ", MAX_TEXT_SIZE - 1);
            fgets(ciphertext, MAX_TEXT_SIZE, stdin);
            ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline
            
            shift = get_shift_value();
            decrypt_caesar(ciphertext, plaintext, shift);
            printf("Decrypted text: %s\n", plaintext);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    printf("Exiting the program. Goodbye!\n");
    return 0;
}

void display_menu() {
    printf("\n----- CAESAR CIPHER -----\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int get_shift_value() {
    int shift;
    do {
        printf("Enter shift value (0 to %d): ", ALPHABET_SIZE - 1);
        scanf("%d", &shift);
        if (shift < 0 || shift >= ALPHABET_SIZE) {
            printf("Invalid shift value. Please enter a value between 0 and %d.\n", ALPHABET_SIZE - 1);
        }
    } while (shift < 0 || shift >= ALPHABET_SIZE);
    return shift;
}

void encrypt_caesar(const char *plaintext, char *ciphertext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0' && i < MAX_TEXT_SIZE - 1; i++) {
        char ch = plaintext[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % ALPHABET_SIZE + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % ALPHABET_SIZE + 'a';
        }
        // Non-alphabet characters remain unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

void decrypt_caesar(const char *ciphertext, char *plaintext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0' && i < MAX_TEXT_SIZE - 1; i++) {
        char ch = ciphertext[i];
        
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE + 'a';
        }
        // Non-alphabet characters remain unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}