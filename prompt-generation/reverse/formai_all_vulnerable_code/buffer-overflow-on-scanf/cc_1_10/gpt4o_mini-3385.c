//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void caesar_cipher(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; ++i) {
        char ch = input[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            input[i] = (ch - base + shift) % 26 + base; 
        }
    }
}

void caesar_decipher(char *input, int shift) {
    caesar_cipher(input, 26 - (shift % 26));  // Reverse the shift
    // Shocked? You can simply reverse the encryption by wrapping around the alphabet!
}

void xor_cipher(char *input, char *key) {
    int key_len = strlen(key);
    for (int i = 0; input[i] != '\0'; ++i) {
        input[i] ^= key[i % key_len];
    }
}

void user_input(char *buffer, size_t size) {
    printf("Enter your message: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

void display_menu() {
    printf("\n----------------------\n");
    printf("Cryptography Options:\n");
    printf("1. Caesar Cipher\n");
    printf("2. XOR Cipher\n");
    printf("0. Exit\n");
    printf("----------------------\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_LEN];
    int choice;
    int shift;
    char key[MAX_LEN];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter the shift value for Caesar Cipher (0-25): ");
                scanf("%d", &shift);
                getchar(); // Clear the newline character

                user_input(input, MAX_LEN);
                caesar_cipher(input, shift);
                printf("Encrypted message (Caesar Cipher): %s\n", input);

                caesar_decipher(input, shift);
                printf("Decrypted message (Caesar Cipher): %s\n", input);
                break;

            case 2:
                printf("Enter the key for XOR Cipher: ");
                fgets(key, MAX_LEN, stdin);
                key[strcspn(key, "\n")] = 0; // Remove newline character

                user_input(input, MAX_LEN);
                xor_cipher(input, key);
                printf("Encrypted message (XOR Cipher): %s\n", input);

                xor_cipher(input, key);  // XOR again to decrypt
                printf("Decrypted message (XOR Cipher): %s\n", input);
                break;

            case 0:
                printf("Exiting... Stay safe in the world of cryptography!\n");
                return 0;

            default:
                printf("Invalid choice! Choose again, or prepare to be shocked!\n");
                break;
        }
    }
    return 0;
}