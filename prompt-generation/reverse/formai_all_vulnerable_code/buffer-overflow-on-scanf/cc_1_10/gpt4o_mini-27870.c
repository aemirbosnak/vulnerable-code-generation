//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
        }
        text[i] = ch;
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decrypting is just encrypting with the complementary shift
}

// Function to read input text from user
void read_input(char *buffer, size_t size) {
    printf("Enter your text (max %zu chars): ", size - 1);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    }
}

// Function to display the menu and read choice
int display_menu() {
    int choice;
    printf("\n*** Caesar Cipher Cryptography ***\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character left by scanf
    return choice;
}

int main() {
    char text[256];
    int shift;
    int choice;

    while (1) {
        choice = display_menu();
        switch (choice) {
            case 1:
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume newline character
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    continue;
                }
                read_input(text, sizeof(text));
                encrypt(text, shift);
                printf("Encrypted Text: %s\n", text);
                break;

            case 2:
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume newline character
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    continue;
                }
                read_input(text, sizeof(text));
                decrypt(text, shift);
                printf("Decrypted Text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}