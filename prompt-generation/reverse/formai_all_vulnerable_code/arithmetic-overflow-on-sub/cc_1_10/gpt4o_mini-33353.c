//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void clear_buffer() {
    while (getchar() != '\n');
}

void caesar_encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            text[i] = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            text[i] = (ch + key - 'a') % 26 + 'a';
        }
    }
}

void caesar_decrypt(char *text, int key) {
    caesar_encrypt(text, 26 - key); // Decrypt by encrypting with (26 - key)
}

void generate_key() {
    srand(time(NULL)); // Seed the random number generator
    int key = rand() % 26; // Random key between 0 and 25
    printf("Generated key: %d\n", key);
}

void display_menu() {
    printf("\nSimple Caesar Cipher Implementation\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Generate Random Key\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char text[MAX_LENGTH];
    int key = 0;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);
        clear_buffer();

        switch (option) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                // Remove trailing newline if exists
                text[strcspn(text, "\n")] = 0;
                printf("Enter key (0-25): ");
                scanf("%d", &key);
                clear_buffer();
                caesar_encrypt(text, key);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0;
                printf("Enter key (0-25): ");
                scanf("%d", &key);
                clear_buffer();
                caesar_decrypt(text, key);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                generate_key();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}